#include "Graph.h"
#include "Quack.h"
#include <stdio.h>
#include <string.h>

#define MAX_WORD_NUMBER 1000
#define MAX_LENGTH 100

int longest_ladder_length = 0;
int longest_ladder_number = 0;

/*
 * remove one character from str,
 * store the result in tempStr
 */
void removeOneCharacter(char* str, char* tempStr, int index)
{
	strncpy(tempStr, str, index);
	strncpy(tempStr+index, str+index+1, strlen(str)-index-1);
	tempStr[strlen(str)-1]='\0';
	return;
}

int differByOne(char* s1, char* s2)
{
	int s1Len = strlen(s1);
	int s2Len = strlen(s2);
	int minLen = s1Len < s2Len ? s1Len : s2Len;	
	int maxLen = s1Len + s2Len + 1 - minLen;
	
	/*check 1 conditions*/
	int sameCharacterNumber = 0;
	for(int i = 0; i < minLen; i++)
	{
		if(s1[i] == s2[i])
		{
			sameCharacterNumber += 1;
		}
	}
	
	/*has the same len and one letter different*/
	if(s1Len == s2Len && sameCharacterNumber == s1Len - 1)
	{
		return 1;
	}
	
	/*remove one letter from s1, check whether same as s2*/
	char* tempStr = (char*)malloc(maxLen*sizeof(char));
	for(int i = 0; i < s1Len; i++)
	{
		removeOneCharacter(s1, tempStr, i);
		if(strcmp(tempStr, s2) == 0)
		{
			free(tempStr);
			return 1;
		}
	}
	
	/*remove one letter from s2, check whether same as s1*/
	for(int i = 0; i < s2Len; i++)
	{
		removeOneCharacter(s2, tempStr, i);
		if(strcmp(tempStr, s1) == 0)
		{
			free(tempStr);
			return 1;
		}
	}
	
	/*return false*/
	free(tempStr);
	return 0;
}


void clearVisit(int* visit, int word_num)
{
	for(int i = 0; i < word_num; i++)
	{
		visit[i] = 0;
	}
	return;
}

void dfs_find_longest_path_len(Graph graph, int word_num, int* visit, int vertex, int current_depth)
{
	//printf("vertex=%d depth=%d\n", vertex, current_depth);
	for(int i = vertex + 1; i < word_num; i++)
	{
		if(visit[i] == 0 && isEdge(newEdge(vertex, i), graph))
		{
			visit[i] = 1;
			dfs_find_longest_path_len(graph, word_num, visit, i, current_depth+1);
			visit[i] = 0;
		}
	}
	
	//update longest_ladder_length
	longest_ladder_length=longest_ladder_length>current_depth?longest_ladder_length:current_depth;
	return;
}


void showPath(Quack quack, char (*word)[MAX_LENGTH])
{
	Quack tempQuack = createQuack();
	while(!isEmptyQuack(quack))
	{
		push(pop(quack), tempQuack);
	}

	int itemIndex = pop(tempQuack);
	printf("%2d: %s", longest_ladder_number, word[itemIndex]);
	push(itemIndex, quack);
	while(!isEmptyQuack(tempQuack))
	{
		int itemIndex = pop(tempQuack);
		push(itemIndex, quack);
		printf(" -> %s", word[itemIndex]);
	}
	printf("\n");	

	destroyQuack(tempQuack);
	return;
}

void dfs_find_longest_path(Graph graph, int word_num, int* visit, int vertex, int current_depth, Quack quack, char (*word)[MAX_LENGTH])
{
	

	for(int i = vertex + 1; i < word_num; i++)
	{
		if(visit[i] == 0 && isEdge(newEdge(vertex, i), graph))
		{
			visit[i] = 1;
			push(i, quack);
			dfs_find_longest_path(graph, word_num, visit, i, current_depth+1, quack, word);
			visit[i] = 0;
			pop(quack);
		}
	}
	
	if(current_depth == longest_ladder_length && longest_ladder_number < 99)
	{
		longest_ladder_number += 1;
		showPath(quack, word);	
		return;
	}

	return;
}

int main()
{
	
	char word[MAX_WORD_NUMBER][MAX_LENGTH];
	int word_num = 0;

	printf("Dictionary\n");
	while(fscanf(stdin, "%s", word[word_num]) != EOF)
	{
		if(word_num > 0 && strcmp(word[word_num-1], word[word_num]) == 0)
		{
			continue;
		}
		printf("%d: %s\n", word_num, word[word_num]);
		word_num += 1;
	}
	
	Graph graph = newGraph(word_num);
	
	for(int i = 0; i < word_num; i++)
	{
		for(int j = i + 1; j < word_num; j++)
		{
			if(differByOne(word[i], word[j]))
			{
				insertEdge(newEdge(i, j), graph);
			}
		}
	}
	
	printf("Ordered Word Ladder Graph\n");
	showGraph(graph);

	int* visit = (int*)malloc(word_num*sizeof(int));
	for(int i = 0; i < word_num; i++)
	{
		clearVisit(visit, word_num);
		visit[i] = 1;
		dfs_find_longest_path_len(graph, word_num, visit, i, 1);
	}
	
	printf("Longest ladder length: %d\n", longest_ladder_length);
	printf("Longest ladders:\n");
	Quack quack = createQuack();
	for(int i = 0; i < word_num; i++)
	{
		clearVisit(visit, word_num);
		makeEmptyQuack(quack);
		visit[i] = 1;
		push(i, quack);
		dfs_find_longest_path(graph, word_num, visit, i, 1, quack, word);
	}

	freeGraph(graph);
	destroyQuack(quack);
	free(visit);
	return 0;
}









