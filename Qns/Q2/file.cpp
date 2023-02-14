#include <bits/stdc++.h>
using namespace std;
//IPL TEAM SCHEDULE DESIGN
struct Node{
    char* arr;
    struct Node* next;
}*head = NULL;
void InsertionAtBeginning(char* data){
    struct Node* temp = (struct Node*) malloc(sizeof(Node));
    temp->arr = data;
    temp->next = NULL;
    if(head == NULL) {
        head = temp;
        return;
    }
    temp->next = head;
    head = temp;
}
void DeletionAtPos(int q){
    int pos = q;
    char* array;
    struct Node* temp = head;
    if(pos == 0){
        head = head->next;
        array = temp->arr;
        temp->next = NULL;
        free(temp);
        for(int i =0;i<strlen(array);i++){
            cout<<char(toupper(array[i]));
        }
    }
    else{
        for(int i = 0;i<pos-1;i++){
            temp = temp->next;
        }
        struct Node* del = temp->next;
        temp->next = temp->next->next;
        array = del->arr;
        free(del);
        for(int i =0;i<strlen(array);i++){
            cout<<char(toupper(array[i]));
        }
    }
}
int main() {
    printf("Enter number of pairs of team names for which you want to schedule matches:\n");
    int n;
    cin>>n;
    for(int i = 0;i<2*n;i++){
        printf("Enter team-%d name: \n",i+1);
        char* arr = (char*)malloc(sizeof (char)*10);
        cin>>arr;
        InsertionAtBeginning(arr);
    }
    srand(time(0));
    int count = 0;
    int val = 2*n;
    cout<<"The schedule for above teams is :\n";
    vector<string> v = {"CHINNA SWAMY STADIUM","EDEN GARDENS","M.A.CHIDAMBARAM STADIUM","WANKHEDE STADIUM","ARUN JAITLEY STADIUM"};
    cout<<"++++++++++++++++******"<<endl;
    while(count<n){
        int k = rand()%val;
        DeletionAtPos(k);
        cout<<" VS ";
        val -= 1;
        int l = rand()%val;
        DeletionAtPos(l);
        cout<<" ->venue: ";
        cout<<v[count];
        val -= 1;
        count++;
        cout<<endl;
    }
    cout<<"++++++++++++++++******"<<endl;
}
