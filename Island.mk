##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Island
ConfigurationName      :=Debug
WorkspaceConfiguration :=Debug
WorkspacePath          :=/home/qurao/dev/GameDev/GameDev
ProjectPath            :=/home/qurao/dev/GameDev/GameDev/Island
IntermediateDirectory  :=../build-$(WorkspaceConfiguration)/Island
OutDir                 :=$(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=qurao
Date                   :=07/11/22
CodeLitePath           :=/home/qurao/.codelite
MakeDirCommand         :=mkdir -p
LinkerName             :=/usr/bin/g++
SharedObjectLinkerName :=/usr/bin/g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputDirectory        :=/home/qurao/dev/GameDev/GameDev/build-$(WorkspaceConfiguration)/bin
OutputFile             :=../build-$(WorkspaceConfiguration)/bin/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :=$(IntermediateDirectory)/ObjectsList.txt
PCHCompileFlags        :=
LinkOptions            :=  -O0 -lSDL2 lSDL2_ttf
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch)include $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch). $(LibraryPathSwitch)Debug 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overridden using an environment variable
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++
CC       := /usr/bin/gcc
CXXFLAGS :=  -g -Wall $(Preprocessors)
CFLAGS   :=   $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/src_Stage_DefaultStage.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_Graphics_AsciiSprite.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_Core_Renderer.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_Core_Window.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_Core_Game.cpp$(ObjectSuffix) $(IntermediateDirectory)/main.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: MakeIntermediateDirs $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) "$(IntermediateDirectory)"
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@$(MakeDirCommand) "$(IntermediateDirectory)"
	@$(MakeDirCommand) "$(OutputDirectory)"

$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "$(IntermediateDirectory)"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/src_Stage_DefaultStage.cpp$(ObjectSuffix): src/Stage/DefaultStage.cpp $(IntermediateDirectory)/src_Stage_DefaultStage.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/qurao/dev/GameDev/GameDev/Island/src/Stage/DefaultStage.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_Stage_DefaultStage.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_Stage_DefaultStage.cpp$(DependSuffix): src/Stage/DefaultStage.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_Stage_DefaultStage.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_Stage_DefaultStage.cpp$(DependSuffix) -MM src/Stage/DefaultStage.cpp

$(IntermediateDirectory)/src_Stage_DefaultStage.cpp$(PreprocessSuffix): src/Stage/DefaultStage.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_Stage_DefaultStage.cpp$(PreprocessSuffix) src/Stage/DefaultStage.cpp

$(IntermediateDirectory)/src_Graphics_AsciiSprite.cpp$(ObjectSuffix): src/Graphics/AsciiSprite.cpp $(IntermediateDirectory)/src_Graphics_AsciiSprite.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/qurao/dev/GameDev/GameDev/Island/src/Graphics/AsciiSprite.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_Graphics_AsciiSprite.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_Graphics_AsciiSprite.cpp$(DependSuffix): src/Graphics/AsciiSprite.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_Graphics_AsciiSprite.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_Graphics_AsciiSprite.cpp$(DependSuffix) -MM src/Graphics/AsciiSprite.cpp

$(IntermediateDirectory)/src_Graphics_AsciiSprite.cpp$(PreprocessSuffix): src/Graphics/AsciiSprite.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_Graphics_AsciiSprite.cpp$(PreprocessSuffix) src/Graphics/AsciiSprite.cpp

$(IntermediateDirectory)/src_Core_Renderer.cpp$(ObjectSuffix): src/Core/Renderer.cpp $(IntermediateDirectory)/src_Core_Renderer.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/qurao/dev/GameDev/GameDev/Island/src/Core/Renderer.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_Core_Renderer.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_Core_Renderer.cpp$(DependSuffix): src/Core/Renderer.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_Core_Renderer.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_Core_Renderer.cpp$(DependSuffix) -MM src/Core/Renderer.cpp

$(IntermediateDirectory)/src_Core_Renderer.cpp$(PreprocessSuffix): src/Core/Renderer.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_Core_Renderer.cpp$(PreprocessSuffix) src/Core/Renderer.cpp

$(IntermediateDirectory)/src_Core_Window.cpp$(ObjectSuffix): src/Core/Window.cpp $(IntermediateDirectory)/src_Core_Window.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/qurao/dev/GameDev/GameDev/Island/src/Core/Window.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_Core_Window.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_Core_Window.cpp$(DependSuffix): src/Core/Window.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_Core_Window.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_Core_Window.cpp$(DependSuffix) -MM src/Core/Window.cpp

$(IntermediateDirectory)/src_Core_Window.cpp$(PreprocessSuffix): src/Core/Window.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_Core_Window.cpp$(PreprocessSuffix) src/Core/Window.cpp

$(IntermediateDirectory)/src_Core_Game.cpp$(ObjectSuffix): src/Core/Game.cpp $(IntermediateDirectory)/src_Core_Game.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/qurao/dev/GameDev/GameDev/Island/src/Core/Game.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_Core_Game.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_Core_Game.cpp$(DependSuffix): src/Core/Game.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_Core_Game.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_Core_Game.cpp$(DependSuffix) -MM src/Core/Game.cpp

$(IntermediateDirectory)/src_Core_Game.cpp$(PreprocessSuffix): src/Core/Game.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_Core_Game.cpp$(PreprocessSuffix) src/Core/Game.cpp

$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/qurao/dev/GameDev/GameDev/Island/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM main.cpp

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)

