#include<iostream>
#include<cstdlib>
#include<vector>
#include<fstream>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;

struct basic_block
{
  string inst[20];
  int inst_count;
  struct basic_block *direct_flow;
  struct basic_block *indirect_flow;
};

int main()
{

vector<string> v;
  ifstream in("ip.txt");

  if(!in) {
    cout << "Cannot open input file.\n";
    return 1;
  }
  char str[255];
  int i=0;
  while(in) {
    in.getline(str, 255); 

  v.push_back(str);

  }

  //finding out leaders
  vector<string> leaders;
  for(i=0;i<v.size();i++)
  {
    if(i==0)
    {
      leaders.push_back(v[i]); //first statement is a leader
    }
    else
    {

	  int pos=v[i].find("if");
	  int gpos=v[i].find("goto");
       if(pos >= 0 || gpos >= 0)
       {
         int goto_pos=v[i].find("goto");
         string bran_pos=v[i].substr(goto_pos+4);
         int open_pos=bran_pos.find("(");
         int close_pos=bran_pos.find(")");
         string new_num=bran_pos.substr(open_pos+1,close_pos-2); //next jump

        for(int k=0;k<v.size();k++)
        {
          int pos_label=v[k].find("label");
	  if (pos_label==0)
	  {
		  string pos_lead=v[k].substr(pos_label+6);
		  if( new_num.compare(pos_lead)==0)
		  {
		    leaders.push_back(v[k]);
		  }
	  }
        }
       }

    }
  }

set<string> st;
for(i=0;i<leaders.size();i++)
    st.insert(leaders[i]);

set<string>::iterator it1,it2;
  for (it1 = st.begin(); it1!=st.end();  ++it1)
  {
    //using all the leader statements	
    cout << *it1 << endl;
  }
in.close();

ifstream in2("ip.txt");

if(!in2) {
  cout << "Cannot open input file.\n";
  return 1;
}
struct basic_block *bblock;
bblock=new basic_block[st.size()];
int bb_count=0;

while(in2) {
  in2.getline(str, 255);
  it2 = st.find(str);
  if(it2!=st.end()){
      bblock[bb_count].inst_count=0;
      bblock[bb_count].inst[bblock[bb_count].inst_count++]=str;
      bb_count++;
  }
  else
  bblock[bb_count-1].inst[bblock[bb_count-1].inst_count++]=str;
}

ofstream out;
out.open("op-basic-block.txt");
cout<<"\n\n"<<endl;
for(int i=0;i<bb_count;i++){
  out<<"Basic_block"<<endl;
  for(int j=0;j<bblock[i].inst_count;j++){
    cout<<bblock[i].inst[j]<<endl;
    out<<bblock[i].inst[j]<<endl;
  }
  out<<"\n"<<endl;
  cout<<"\n"<<endl;
}



  return 0;

}
