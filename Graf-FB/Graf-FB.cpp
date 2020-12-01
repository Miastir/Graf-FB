#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
 
using namespace std;

int main() // �������� ���������
{
setlocale(LC_ALL, "Rus");

    vector<int> parent(6,-1);    // ���������� ������� � ���������� ���������� -1
    
    int Infinity(10000);// �������� �������������, ����� ������� �����
    
    
	 int matrix[6][6] = {{0,3,0,0,6,20},//������� ����� �����
                        {3,0,8,3,0,0},
                        {0,8,0,4,0,5},
                        {0,3,4,0,0,0},
                        {6,0,0,0,0,7},
                        {20,0,5,0,7,0},
						};
	    //����� ���������� ��������
    cout << " matrix smejnosti :"<<endl;      
    
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
            cout << matrix[i][j] << "\t";
        cout << endl;
    }
// �������� ����� ������
int a[6][6] = {{0,3,1000,1000,6,20},//������� ����� ����� 1000-��� ������ �������������
                        {3,0,8,3,1000,1000},
                        {1000,8,0,4,1000,5},
                        {1000,3,4,0,1000,1000},
                        {6,1000,1000,1000,0,7},
                        {20,1000,5,1000,7,0},};

//��������� �������                        
cout << endl;
 //������ �� ������� ��������� ����� ��������� ����� ���������
    for (int k = 0; k < 6; k++)
        for (int i = 0; i < 6; i++)
            for (int j = 0; j < 6; j++)
                if (a[i][j] > a[i][k] + a[k][j]) //���� �� �������� ����� ��������� ����� �������� ����������� ������ ������ ��������
                    a[i][j] = a[i][k] + a[k][j];
                    
                    
//��������
int pos[6],node[6],min(0),index_min(0);
    for(int i = 0;i<6;++i){// ��������� ������� ��������������� ��� ������
        pos[i] = Infinity;// ������ ���������� �� ������ �� ��������
        node[i] = 0; // ������ ��������� ������
        
    }
    
   //����� ������� ����� �����
    for(int i = 0;i<6;++i){
        for(int j = 0;j<6;++j){
            cout << setw(4) << matrix[i][j];
        }
        cout << "\n";
    }
    //�������� ��������� �������
    int l,p;
    std::cout << "\n v vedite vershiny home : ";
    std::cin >> l;
    pos[l-1] = 0;            
    
    
    p=1;
    for(int i = 0 ;i<5 && (p>0);++i){
        min = Infinity;               
        p=0;
		    for(int j = 0;j<6;++j){
        	
            if(!node[j] && pos[j] < min){
                min = pos[j];
                index_min = j;
                p=1;
            }
        }
        node[index_min] = true;
    
   
		                
        for(int j = 0;j<6;++j){
        	/*              �������� ����� ����� ��������� � ����� ����                              */
            if(!node[j] && matrix[index_min][j] > 0 && pos[index_min] != Infinity && pos[index_min] + matrix[index_min][j] < pos[j]){
                pos[j] = pos[index_min] + matrix[index_min][j];
                parent.at(j) = index_min;    // ���������� ������ ������� j
            }
        } 
                    
                    

//�������� ������ ������
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
            cout << a[i][j] << "\t";
        cout << endl;
    }
  int n(0);
    
    std::cout << "\n v vedite vershiny end : ";
    std::cin >> n;
 
    vector<int>temp;     // 
    
    for(int i = n-1;i != -1;i = parent.at(i))temp.push_back(i+1);   
    reverse(temp.begin(),temp.end());
    
    std::cout <<"\n"<< "min marshrut: "<< "\n";
    for(int i = 0;i<temp.size();++i){
	std::cout << temp.at(i) << " ";}
        
        
    std::cout <<"\n"<< "dlinna puti : " << pos[n-1] << "\n";
    
    //����� ���� ���� �����
    std::cout <<"\n"<< "dlinna puti do vsex vershin is vershini "<<l<<"\n";
    for(int i = 0;i<6;++i){    
    std::cout <<l<< "-"<< i+1 << "=" << pos[i] << "\n";
}
 
    std::cout << endl;
    
system("pause");
}}
