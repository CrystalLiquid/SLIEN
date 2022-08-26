#include <string>
#include <iostream>
#include <fstream>


#ifndef IO_SL
#define IO_SL

#pragma once
#define EOF (-1)
//String IO
using namespace std;

extern "C"{
	namespace StrIO{
	#define OUT_ADD 1
	#define OUT_CRE 0
	#define OUT_OvR 2
	string StrRead(const char * FP);
	int StrWrite(const char *Name,string * W_CONTENT,const char * FP ,int Option);
	int StrWr_Add(const char *Name,string * W_CONTENT,const char * FP);
	int StrWr_Ovr(const char *Name,string * W_CONTENT,const char * FP);
	int StrWr_CRE(const char *Name,string * W_CONTENT);	
	}
	
	namespace BinIO{
		struct Buffer{
			
		};
	}
	namespace KeyBoard{
		struct Keys{
			int KetState;
			char cBuffer;
			int Buffer;
		};
		int GetKeys();
		
	}
	namespace SLI_VDF{
		struct SLVDF{
			char * CONTENT;
			SLVDF * Head;
			SLVDF * Prev;
			SLVDF * Next;
		};
		string ReadVDF(const char * FilePath);
		void PraseVDF(const char * FilePath);
		void WriteVDF(const char * FileName);
		
	}	
	
}


#endif
