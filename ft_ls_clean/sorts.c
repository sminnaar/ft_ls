/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 12:14:01 by tcajee            #+#    #+#             */
/*   Updated: 2019/09/04 18:11:11 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <assert.h>
#define lenof(x) (sizeof(x)/sizeof(*(x)))
#include <stdio.h>
#include <string.h>
#define nmax 13
element k[nmax];

typedef struct element element;
struct element {
element *next, *prev;
int i;
};

int cmp(element *a, element *b) {
return a->i - b->i;
}

/*
* This is the actual sort function. Notice that it returns the new
* head of the list. (It has to, because the head will not
* generally be the same element after the sort.) So unlike sorting
* an array, where you can do
* 
*     sort(myarray);
* 
* you now have to do
* 
*     list = listsort(mylist);
*/
element *listsort(element *list, int is_circular, int is_double) {
element *p, *q, *e, *tail, *oldhead;
int insize, nmerges, psize, qsize, i;
/*
* Silly special case: if `list' was passed in as NULL, return
* NULL immediately.
*/
if (!list)
	return NULL;
insize = 1;
	while (1)
	{
		p = list;
		oldhead = list;		       /* only used for circular linkage */
		list = NULL;
		tail = NULL;
		nmerges = 0;  /* count number of merges we do in this pass */
		while (p)
		{
			nmerges++;  /* there exists a merge to be done */
			/* step `insize' places along from p */
			q = p;
			psize = 0;
			for (i = 0; i < insize; i++)
			{
				psize++;
				if (is_circular)
					q = (q->next == oldhead ? NULL : q->next);
				else
					q = q->next;
				if (!q)
					break;
			}
			/* if q hasn't fallen off end, we have two lists to merge */
			qsize = insize;
			/* now we have two lists; merge them */
			while (psize > 0 || (qsize > 0 && q))
			{
				/* decide whether next element of merge comes from p or q */
				if (psize == 0)
				{
				/* p is empty; e must come from q. */
					e = q; q = q->next; qsize--;
					if (is_circular && q == oldhead)
						q = NULL;
				}
				else if (qsize == 0 || !q)
				{
					/* q is empty; e must come from p. */
					e = p; p = p->next; psize--;
					if (is_circular && p == oldhead)
						p = NULL;
				}
				else if (cmp(p,q) <= 0)
				{
					/* First element of p is lower (or same);
					* e must come from p. */
					e = p; p = p->next; psize--;
					if (is_circular && p == oldhead)
						p = NULL;
				}
				else
					{
					/* First element of q is lower; e must come from q. */
					e = q; q = q->next; qsize--;
					if (is_circular && q == oldhead)
						q = NULL;
				}
				/* add the next element to the merged list */
				if (tail)
				{
					tail->next = e;
				}
				else
				{
					list = e;
				}
				if (is_double)
				{
					/* Maintain reverse pointers in a doubly linked list. */
					e->prev = tail;
				}
				tail = e;
			}
			/* now p has stepped `insize' places along, and q has too */
			p = q;
		}
		if (is_circular)
		{
			tail->next = list;
			if (is_double)
			list->prev = tail;
		}
		else
			tail->next = NULL;
		/* If we have done only one merge, we're finished. */
		if (nmerges <= 1)   /* allow for nmerges==0, the empty list case */
			return list;
		/* Otherwise repeat, merging lists twice the size */
		insize *= 2;
	}

}

/*
* Small test rig.
*/


int print_and_check_list(element *head, int expected_len,
int is_circular, int is_double,
int check_ordering)
{
unsigned long bits_used;
element *tail, *e;

assert(expected_len <= 32);        /* so bit mask fits in unsigned long */

/*
* Check over the list in the forward direction, to find its tail
* and make sure it covers exactly the expected set of elements.
*/
bits_used = 0;
e = head;
do {
unsigned long bit;

if (!(e >= k && e < k+expected_len)) {
printf("!! Out-of-range pointer !!");
return 0;
}

bit = 1U << (e - head);
if (bits_used & bit) {
printf("!! Duplicate element !!");
return 0;
}
bits_used |= bit;

tail = e;
e = e->next;
} while (e && e != head);

/*
* Check links at the ends.
*/
if (tail->next != (is_circular ? head : NULL)) {
printf("!! Bad next link from list tail !!");
return 0;
}
if (is_double && head->prev != (is_circular ? tail : NULL)) {
printf("!! Bad prev link from list head !!");
return 0;
}

/*
* Check backward links in the rest of the list.
*/
if (is_double) {
for (e = head; e->next && e->next != head; e = e->next) {
if (e->next->prev != e) {
printf("!! Bad prev link from node %d '%c' !!",
(int)(e->next - k), e->next->i);
return 0;
}
}
}

/*
* Check the list is sorted.
*/
if (check_ordering) {
for (e = head; e->next && e->next != head; e = e->next) {
if (!(e->next->i > e->i)) {
printf("!! Bad ordering between nodes %d '%c' and %d '%c' !!",
(int)(e - k), e->i, (int)(e->next - k), e->next->i);
return 0;
}
}
}

/*
* Everything looks OK. Print the list.
*/
putchar('[');
e = head;
do {
putchar(e->i);
e = e->next;
} while (e && e != head);
putchar(']');
return 1;
}

int main(void) {
/*
* Some test lists to sort, represented as strings for brevity.
*/
static const char *const testcases[] = {
/*
* Three orders of a length-13 list. (The length is chosen
* because that means some passes will have an extra list at
* the end and some will not.)
*/
"abcdefghijklm",
"gcielbmhdjfak",
"mlkjihgfedcba",
};

int is_circular, is_double;
int npasses = 0, nfails = 0;

listsort(NULL, 0, 0);

for (is_circular = 0; is_circular < 2; is_circular++) {
for (is_double = 0; is_double < 2; is_double++) {
printf("testing %s %s linked list\n",
is_circular ? "circular" : "straight",
is_double ? "doubly" : "singly");
int i;
for (i = 0; i < (int)lenof(testcases); i++) {
int pass = 1;
element *head;
int j;

/*
* Set up a linked-list representation of the string
* testcases[i].
*/

int n = strlen(testcases[i]);
assert(n <= nmax);

for (j = 0; j < n; j++) {
k[j].i = testcases[i][j];
k[j].next = (j+1 < n ? &k[j+1] :
is_circular ? &k[0] : NULL);
k[j].prev = (!is_double ? NULL :
j > 0 ? &k[j-1] :
is_circular ? &k[n-1] : NULL);
}

head = &k[0];

/*
* Test-sort it, printing the list before and after,
* and checking all its consistency properties.
*/

printf("    ");
if (!print_and_check_list(head, n,
	  is_circular, is_double, 0)) {
pass = 0;
} else {
head = listsort(head, is_circular, is_double);
printf(" -> ");
if (!print_and_check_list(head, n,
		  is_circular, is_double, 1))
pass = 0;
}

if (pass) {
printf(" ok");
npasses++;
} else {
nfails++;
}
printf("\n");
}
}
}
printf("passed %d failed %d total %d\n", npasses, nfails, npasses+nfails);
return nfails != 0;
}
