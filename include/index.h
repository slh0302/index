#ifndef _INDEX_H_
#define _INDEX_H_

#include<algorithm>
#include<iostream>
#include<fstream>
#include<string>
#include<map>
#define TOTALBYTESIZE 1024
#define BYTE_INDEX  16
#define INITAL_TOTAL_SIZE 0

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::map;


//��¼һ��λ��������
extern int table[( 1 << BYTE_INDEX )];
extern unsigned short record[TOTALBYTESIZE/BYTE_INDEX];
extern map<int, int> labelList;
/*******************************************
	SortTable:������������ݽṹ
	sum����¼���ֵ
	string���洢�����infoֵ

*******************************************/
struct SortTable{
	int sum;
	int info;
	bool operator<(const SortTable& A)const{
		return sum < A.sum;
	}
	bool operator>(const SortTable& A)const{
		return sum > A.sum;
	}
};


struct DataSet
{
	int data[TOTALBYTESIZE/BYTE_INDEX];
};
struct Info_String
{
	char info[100];
};
/******************************************
	Feature:����������
	���ݣ�
		label�����������ǩ
		data����Ű�λ�ָ�����������
		bytesize��������ݵİ�λ�ָ���С
	������

		init(int size):
			��ʼ����������ʼ��bytesize��data�Ŀռ�
		void setData(int label, int* data):
			Data������set����
		int* getData()��
			Data��
			����get����
*******************************************/
class feature{
private:
	DataSet* Set;
	Info_String* info;
	int count;int str_count;
	//totalSize���ܵ�����ռ��С
	int totalSize ;
public:
	feature() :Set(NULL), count(0), totalSize(INITAL_TOTAL_SIZE){}
	void setCount(int count){
		this->count = count;
		this->str_count = count;
	}
	int getTotalSize(){
		return this->totalSize;
	}
	void setTotalSize(int size){
		this->totalSize = size;
	}
	int getCount(){
		//this->count = count;
		return this->count;
	}

	void setDataSet(DataSet* set,int co){
		count=co;
		this->Set = set;
		if (totalSize == 0){
			totalSize = count;
		}
	}
	Info_String* getInfoSet(){
		return this->info;
	}
	void setInfo(Info_String* info, int co){
		str_count = co;
		this->info = info;
		if (totalSize == 0){
			totalSize = count;
		}
	}
	DataSet* getDataSet(){
		return this->Set;
	}
	int* getData(){
		return this->Set->data;
	}
	void deleteData(){
		delete[] Set;
		delete[] info;
	}
};


/****




************************/

template<typename Dtype>
class writeDb{
public:
	void open(string dbName){
		db.open(dbName.c_str());
	}
	void write(const Dtype &data){
		db << data;
	}
	void write(const string& str){
		db << str;
	}
	void close(){
		db.close();
	}
	virtual ~writeDb(){
		db.close();
	}
private:
	std::ofstream db;

};
////��������Ѱ�ҵ�K��
void swap(SortTable *a, SortTable *b);
int partition(SortTable arr[], int left, int right, int pivotIndex);
int findKMax(SortTable arr[], int left, int right, int k);

// ���ú���

int* doHandle(char * dat);
void CreateTable(const char * filename, int bits);
//index ����
/*******************************************
	��ʼ��
	���ܴ���
********************************************/
void InitIndex(void* p,char* filename, Info_String* in_str, int count);

/********************************************
	int bits: ����λ������
	int size: ����������
	����ֵ
		void*�� ��������ֵ
********************************************/
void* CreateIndex(int size);


/********************************************
	�������ݼ�¼
*********************************************/
bool AddToIndex(void*p, int* data,const  char* in);

/*********************************************
	����ർ������
		*p�� ԭ�е�ָ��
		filename: �ļ���
		count: �����������
*********************************************/
bool LoadIndex(void* p, const char* filename, const char*, int count);

/*********************************************
	�ͷ��ڴ�ռ�
*********************************************/
bool DeleteIndex(void* p);

/********************************************
	���л�д���ļ���
		count: index�ĸ���
		filename: �ļ���
		mode: �ļ����ɷ�ʽ  w:д�� a:����
********************************************/
bool ArchiveIndex(void* p, const char* filename, const char*,int count, char mode);

/********************************************
	����������
		input������İ�λ�������
		void *p���������ݿ�
		result��������ص�ͼƬ����info
		bits��������ֵ�λ��
		LIMIT:���������ֵ
*********************************************/
int retrival(int* input, DataSet* get_t,Info_String* get_info,int total, std::string& result, int bits, int LIMIT,SortTable* );

int retrival2(int* input, void* p, std::string& result, int bits, int LIMIT);


void retrival_thread(int* input, DataSet* get_t, int begin,int total, int bits, int LIMIT,SortTable* sorttable, int* line_record);

#endif
