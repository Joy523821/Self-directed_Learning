#include<bits/stdc++.h>///////////---------------------------UNSOLVED-----------------------------
using namespace std;

map<int, int> member;//誰 哪組

//每一個節點
struct node{
    int id; //值，此指人的編號
    node* next; //下一個點是誰
};//struct後面要加分號

//要有insert 跟 pop_front
struct linked_list{
    node *endNode;//開始(恆為空，值=-1)
    node *startNode; //結束(空的時候是-1，不然就最後一點)
    node *lastmember[1005]; //記每組最後一人是哪個node
    //只能放宣告不能放指令
    
    linked_list(){ //建構式
        this->endNode = new node; //new出一個動態記憶體
        this->startNode = new node;

        
        endNode->id = -1;//把頭尾的值設成-1(範圍以外)
        startNode->id = -1;
        startNode->next = endNode;//根指向尾巴
        for(int i = 0;i<=1004;i++){
            this->lastmember[i] = new node;
            lastmember[i]->id = -1;//先預設這團沒有人在隊伍中
        }
        //cout << "constructer";//debug用
        return;
    }
    void insert(int id){ //插入編號為id的人
        node* newNode = new node;
        newNode->id = id; 
        if(startNode->next->id == -1){ //如果還是空的
            endNode = newNode;//尾巴變成id
            startNode->next = newNode;//根的下一個接id(尾巴)
            lastmember[member[id]] = newNode; //第member[id]組最後是newnode
            return;
        }else if(lastmember[member[id]]->id == -1){ //如果有東西但自己組的人不在裡面
            endNode->next = newNode; //尾巴接到newnode
            endNode = newNode; //尾巴變成newnode
            lastmember[member[id]] = newNode; //第member[id]組最後是newnode
        }else{
            auto cur = lastmember[member[id]]; //cur移到同組最後(標記用)
            if(cur->id == endNode->id){//他剛好是最後
                endNode->next = newNode; //尾巴接到newnode
                endNode = newNode; //尾巴變成newnode
                lastmember[member[id]] = newNode; //第member[id]組最後是newnode
            }else{
                newNode->next = cur->next;//新node下一個指到cur下一個
                cur->next = newNode; //cur下一個指到新node
                lastmember[member[id]] = newNode; //第member[id]組最後是newnode
            }
        }
    } //void insert()

    int pop_front(){//移除首位並回傳
        int ret = startNode->next->id;//記錄首位(欲回傳值)
        if(ret == endNode->id){//只有startnode跟有值的endnode(ret == endnode)
            endNode->id = -1;//endnode重置
            return ret;
        }else{//不只start、end
            startNode->next = startNode->next->next; //startNode指到第二位
            return ret;
        }
    }

    ////////////////////////////////////////////////////////////////////////////////////
    void print(){
        auto cur = startNode;
        cout << "[";
        while(1){
            cur = cur->next; 
            cout << cur->id << " ";
            if(cur->id == endNode->id)
                break;
        }
        cout << "]\n";
        return;
    }
    
};



int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int T; //T testdata
    cin >> T;
    for(int times = 1;times <= T; times++){
        //輸入區
        member.clear();
        int group; //幾組人
        cin >> group;
        int group_size,tmp; 
        for(int i = 1; i <= group; i++){ //紀錄第1~n組有誰
            cin >> group_size; //這組有幾人
            while(group_size--){ 
                cin >> tmp;
                member[tmp] = i; //編號tmp的人第i組(i = 1~group)
            }
        }

        //執行區
        linked_list line;
        cout << "Line #"<<times<<"\n";
        int M;//M行指令
        cin >> M;
        
        string command;//////////////////////////跑到ENQUEUE會中斷
        int person;//要插入還是出隊 誰
        while(M--){
            cin >> command;
            if(command == "ENQUEUE"){
                cin >> person;
                line.insert(person);
            }else if(command == "DEQUEUE"){
                cout << line.pop_front()<<"\n";
            }
            //line.print();/////////////////////////////////
        }
    }
}

//沒有組的人都是group0?還是各自一組