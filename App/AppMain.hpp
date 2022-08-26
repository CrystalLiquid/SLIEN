
#include "../Public/CBase.h"
#include "RenderAPI/Utility.h"
#include "RenderAPI/OpenGL.h"
#include "LinMath/linmath.h"
//#include "../SLIEN/RenderAPI/Utility.h"
//#include "../SLIEN/RenderAPI/OpenGL.h"
//#include "../../SLIEN/LinMath/linmath.h"
#include <GL/glext.h>
#include <GL/glu.h>

#ifndef SLAppF
#define SLAppF
#include "RenderAPI/RenderStack_OGL.h"
PFNGLBINDBUFFERPROC glBindBuffer = NULL;
PFNGLBUFFERDATAPROC glBufferData = NULL;
PFNGLGENBUFFERSPROC glGenBuffers = NULL;
PFNGLMAPBUFFERPROC glMapBuffer = NULL;
PFNGLUNMAPBUFFERPROC glUnmapBuffer = NULL;
using namespace StrIO;
extern "C"
{
	void keyboard(unsigned char key, int x, int y);
	void SILEN_DRAWFRAME(GLFWwindow *window, float currentTime);
	void Init(GLFWwindow *window);
	int Hi;
	int Wd;
	float FOV = 90.0f;
}
float vtxp[] = {

	-0.5, -0.5, 0.5,
	    -0.5, 0.5, 0.5,
	    0.5, 0.5, 0.5,
	    0.5, -0.5, 0.5,
	    -0.5, -0.5, -0.5,
	    -0.5, 0.5, -0.5,
	    0.5, 0.5, -0.5,
	    0.5, -0.5, -0.5
    };
const char * VS = StrRead("SILENVTX.VTX").c_str();
const char * FS = StrRead("SILENFRA.FRA").c_str();

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	Aspect = (float)Wd / (float)Hi;
	glViewport(0, 0, width, height);
	mat4x4_perspective(PMat._mat, FOV, Aspect, 0.1f, 1000.0f);

}

struct SLIEN_OPENGL_APP {
#define RENDER_OGL 1244
	public:
		SL_RSTEP SLP;
		bool SwitchDraw = false;
		bool NULLDRAW = false;
	public:
		
		int AppMain(int argc, char **argv, const char * Title) {
			cout << RENDER_OGL << endl;
			cout << "APP STARTED" << endl;
			glfwInit();
			if (!glfwInit()) {
				exit(EXIT_FAILURE);
			}
			glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
			glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
			glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);

			GLFWwindow *window = glfwCreateWindow(Wd, Hi, Title, NULL, NULL);
			glfwMakeContextCurrent(window);
			glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
			Aspect = (float)Wd / (float)Hi;
			mat4x4_perspective(PMat._mat, FOV, Aspect, 0.1f, 1000.0f);
			//if(!gladLoadGLLoader(GLADloadproc)glfwGetProcAdress){
			//

			//}
			cout << "Window Created" << endl;
			glfwSwapInterval(1);
			cout << "Intervaled" << endl;
			Init(window);
			cout << "INITED" << endl;
			while (!glfwWindowShouldClose(window)) {
				if(SwitchDraw == false && NULLDRAW == false){
					
				SILEN_DRAWFRAME(window, glfwGetTime());	
				}
				
				glfwSwapBuffers(window);
				glfwPollEvents();
			}
			glfwDestroyWindow(window);
			glfwTerminate();



			return EXIT_SUCCESS;
		}

		void Verticles() {


			glGenVertexArrays(1, VAOS);
			glBindVertexArray(VAOS[0]);
			glGenBuffers(NVBO, VBOS);
			glBindBuffer(GL_ARRAY_BUFFER, VBOS[0]);
			glBufferData(GL_ARRAY_BUFFER, sizeof(vtxp), vtxp, GL_DYNAMIC_DRAW);
			cout << "SetUp FINISH" << endl;
		}
		void SL_KEYBOARD(unsigned char key, int x, int y) {
			switch (key) {
				case '\x1B':
					exit(EXIT_SUCCESS);
					break;
			}
		}
		void Init(GLFWwindow *window) {
			glewInit();

			RenderProgram = CreateShaderProgram(VS, FS);
			printf("RP Created\n");
			glBindBuffer = (PFNGLBINDBUFFERPROC)wglGetProcAddress("glBindBuffer");
			glBufferData = (PFNGLBUFFERDATAPROC)wglGetProcAddress("glBufferData");
			glGenBuffers = (PFNGLGENBUFFERSPROC)wglGetProcAddress("glGenBuffers");
			glMapBuffer = (PFNGLMAPBUFFERPROC)wglGetProcAddress("glMapBuffer");
			glUnmapBuffer = (PFNGLUNMAPBUFFERPROC)wglGetProcAddress("glUnmapBuffer");
			//	RenderProgram = createShaderProgram();
			CamX = 0;
			CamY = 0;
			CamZ = 0;
			SLP.SLM.MLOCX = 0;
			SLP.SLM.MLOCY = 0;
			SLP.SLM.MLOCZ = 0;
			
			//Avertices();
			Verticles();

		}

		void SILEN_DRAWFRAME(GLFWwindow *window, float currentTime) {
		
			SLP.STEP_GL(0, 36, 1);
			//cout<<SLP.SLM.MLOCX<<" "<<SLP.SLM.MLOCY<<" "<<SLP.SLM.MLOCZ<<" "<<" | ";

			//printf("");
		}


};
typedef SLIEN_OPENGL_APP* SL_Device;



#endif
