#include <vtkSmartPointer.h>
#include <vtkRenderWindow.h>
#include <vtkRenderer.h>
#include <vtkConeSource.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkProperty.h>
#include <vtkPoints.h>
#include <vtkPolyLine.h>
#include <vtkProgrammableFilter.h>
#include <vtkCallbackCommand.h>
#include <vtkPolyDataStreamer.h>
#include <vtkProgrammableDataObjectSource.h>
#include <vtkVertexGlyphFilter.h>
#include <random>
#include "vtkAutoInit.h" 

VTK_MODULE_INIT(vtkRenderingOpenGL2)
VTK_MODULE_INIT(vtkInteractionStyle);

vtkSmartPointer<vtkPoints> points = vtkSmartPointer<vtkPoints>::New();
vtkSmartPointer<vtkPolyData> polyData = vtkSmartPointer<vtkPolyData>::New(); 

float imin(-5);
float imax(5);
std::random_device rd;
std::mt19937_64 rng(rd());
std::uniform_real_distribution<> uni(imin, imax);
unsigned cnt(0);

void init_points() {
  const unsigned n(300000);
  points->SetNumberOfPoints(n);
  for (unsigned i(0); i < n; ++i) {
    points->SetPoint(i, uni(rng), uni(rng), uni(rng)); 
  }
}

void update_points() {
  const unsigned n(300000);
  for (unsigned i(0); i < n; ++i) {
    points->SetPoint(i, uni(rng), uni(rng), uni(rng)); 
  }
}

void TimerCallbackFunction(vtkObject* caller,
                           long unsigned int vtkNotUsed(eventId),
                           void* clientData, void* vtkNotUsed(callData)) {
  std::cout << "cnt:" << cnt++ << std::endl;
  vtkRenderWindowInteractor *renderWindowInteractor =
    static_cast<vtkRenderWindowInteractor*>(caller); 
  update_points(); 
  points->Modified();
  polyData->Modified();
  renderWindowInteractor->Render();
}

int main(int argc, char** argv) {
  init_points();
  polyData->SetPoints(points);
  vtkSmartPointer<vtkVertexGlyphFilter> glyphFilter =
    vtkSmartPointer<vtkVertexGlyphFilter>::New();
  glyphFilter->SetInputData(polyData);
  glyphFilter->Update();

  vtkSmartPointer<vtkPolyDataMapper> mapper =
    vtkSmartPointer<vtkPolyDataMapper>::New();
  mapper->SetInputConnection(glyphFilter->GetOutputPort());
  vtkSmartPointer<vtkActor> actor = vtkSmartPointer<vtkActor>::New();
  actor->SetMapper(mapper);
  vtkSmartPointer<vtkRenderer> renderer = vtkSmartPointer<vtkRenderer>::New();
  vtkSmartPointer<vtkRenderWindow> renderWindow =
    vtkSmartPointer<vtkRenderWindow>::New();
  renderWindow->AddRenderer(renderer);
  vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor =
    vtkSmartPointer<vtkRenderWindowInteractor>::New();
  renderWindowInteractor->SetRenderWindow(renderWindow);
  renderer->AddActor(actor);
  renderer->SetBackground(0, 0, 0);
  renderWindow->Render();
  vtkSmartPointer<vtkCallbackCommand> timerCallback = 
    vtkSmartPointer<vtkCallbackCommand>::New();
  timerCallback->SetCallback(TimerCallbackFunction); 
  renderWindowInteractor->Initialize();
  renderWindowInteractor->CreateRepeatingTimer(1);
  renderWindowInteractor->AddObserver(vtkCommand::TimerEvent, timerCallback);
  renderWindowInteractor->Start();
  return EXIT_SUCCESS;
}
