#include "IO.h"
extern "C" {
	namespace StrIO {
		string StrRead(const char * FP) {
			string CONTENT;
			string Line = "";
			if (FP != NULL) {
				ifstream FS(FP, ios::in);
				while (!FS.eof()) {
					getline(FS, Line);
					CONTENT.append(Line + "\n");
				}//just read them
				FS.close();

			}
			if (FP == NULL) {
				return NULL;
			}

			return CONTENT;//where the contents loaded
		};
		int StrWrite(const char *Name, string * W_CONTENT, const char * FP, int Option = OUT_ADD) {
			ofstream OF;
			if (Option == OUT_ADD) {
				OF.open(FP, ios::out | ios::ate | ios::app);
				OF << (*W_CONTENT);

				OF.close();

			}
			if (Option == OUT_OvR) {
				OF.open(FP, ios::out | ios::trunc);
				OF << (*W_CONTENT);
				OF.close();

			}
			return 1;
		};
		int StrWr_Add(const char *Name, string * W_CONTENT, const char * FP) {
			StrWrite(Name, W_CONTENT, FP, OUT_ADD);
			return 1;
		}
		int StrWr_Ovr(const char *Name, string * W_CONTENT, const char * FP) {
			StrWrite(Name, W_CONTENT, FP, OUT_OvR);
			return 1;
		}
	}

	namespace KeyBoard {
		int GeyKeys() {
#if Windows
			if (_kbhit()) {
				return _getch();
			}
#endif
			return 0;
		}
	}

}
