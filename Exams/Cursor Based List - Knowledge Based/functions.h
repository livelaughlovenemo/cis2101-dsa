#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"

// initVHeap
void initVHeap(VHeap *vh){
    vh->avail = 0;
    for (int i = 0; i < MAX_SIZE - 1; i++){
        vh->H[i].next = i + 1;
    }
    
    vh->H[MAX_SIZE - 1].next = -1;
}
// alloc
int alloc(VHeap *vh){
    if(vh->avail == -1){
        return -1;
    }
    
    int index = vh->avail;
    vh->avail = vh->H[index].next;
    return index;
}
// dealloc
void dealloc(VHeap *vh, int index){
    vh->H[index].next = vh->avail;
    vh->avail = index;
}
// insertArticle
int insertArticle(VHeap *vh, int *List, Article article, int pos){
    int newNode = alloc(vh);
    
    if (newNode == -1){
        printf("Error: Heap is full. Cannot insert new article.\n");
        return 0;
    }
    vh->H[newNode].article = article;
    vh->H[newNode].next = -1;
    
    if (*List == -1 || pos == 0){
        vh->H[newNode].next = *List;
        *List = newNode;
        return 1;
    }
    
    if (pos == - 1){
        int curr = *List;
        while (vh->H[curr].next != -1){
            curr = vh->H[curr].next;
        }
        vh->H[curr].next = newNode;
        return 1;
    }
    int curr = *List;
    int prev = -1;
    int i = 0;
    
    while (curr != -1 && i < pos){
        prev = curr;
        curr = vh->H[curr].next;
        i++;
    }
    
    if(i == pos && prev != -1){
        vh->H[newNode].next = curr;
        vh->H[prev].next = newNode;
        return 1;
    } else {
        dealloc(vh, newNode);
        printf("Invalid Position. Insertion Failed.\n");
        return 0;
    }
}

// viewArticles
void viewArticles(VHeap vh, int List){
    if (List == -1){
        printf("The knowledge base is empty.\n");
        return;
    }
    
    printf("\n--- List of Articles ---\n");
    int curr = List;
    
    while (curr != -1){
        printf("ID: %d | Title: %s\n", vh.H[curr].article.id, vh.H[curr].article.title);
        curr = vh.H[curr].next;
    }
    printf("------------------------\n\n");
}
// searchArticle
void searchArticle(VHeap vh, int List, int id){
    int curr = List;
    while(curr != -1){
        if(vh.H[curr].article.id == id){
            printf("\n--- Article Found ---\n");
            printf("ID: %d\n", vh.H[curr].article.id);
            printf("Title: %s\n", vh.H[curr].article.title);
            printf("Content: %s\n", vh.H[curr].article.content);
            printf("---------------------\n\n");
            return;
        }
        curr = vh.H[curr].next;
    }
    printf("Article with ID %d not found.\n\n", id);
}

// deleteArticle
int deleteArticle(VHeap *vh, int *List, int id){
    if(*List == -1){
        printf("The knowledge base is empty.\n\n");
        return 0;
    }
    int curr = *List;
    int prev = -1;
    
    while (curr != -1 && vh->H[curr].article.id != id){
        prev = curr;
        curr = vh->H[curr].next;
    }
    
    if (curr == -1){
        printf("Article with ID %d not found.\n\n", id);
        return 0;
    }
    
    if (prev == -1){
        *List = vh->H[curr].next;
    } else {
        vh->H[prev].next = vh->H[curr].next;
    }
    dealloc(vh, curr);
    printf("Article with ID %d deleted successfully.\n\n", id);
    return 1;
}