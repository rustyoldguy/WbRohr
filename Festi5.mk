##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Festi5
ConfigurationName      :=Debug
WorkspacePath          :=/home/josef/Programmieren/Codeblocks/METALL/FESTI/Festi5
ProjectPath            :=/home/josef/Programmieren/Codeblocks/METALL/FESTI/Festi5/Festi5
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Josef Wismeth 
Date                   :=04/06/21
CodeLitePath           :=/home/josef/.codelite
LinkerName             :=g++
SharedObjectLinkerName :=g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.o.i
DebugSwitch            :=-gstab
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E 
ObjectsFileList        :="Festi5.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := ar rcus
CXX      := g++
CC       := gcc
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/festi.cpp$(ObjectSuffix) $(IntermediateDirectory)/menuefrage.cpp$(ObjectSuffix) $(IntermediateDirectory)/menues.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@test -d ./Debug || $(MakeDirCommand) ./Debug


$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM main.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/josef/Programmieren/Codeblocks/METALL/FESTI/Festi5/Festi5/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp

$(IntermediateDirectory)/festi.cpp$(ObjectSuffix): festi.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/festi.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/festi.cpp$(DependSuffix) -MM festi.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/josef/Programmieren/Codeblocks/METALL/FESTI/Festi5/Festi5/festi.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/festi.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/festi.cpp$(PreprocessSuffix): festi.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/festi.cpp$(PreprocessSuffix) festi.cpp

$(IntermediateDirectory)/menuefrage.cpp$(ObjectSuffix): menuefrage.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/menuefrage.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/menuefrage.cpp$(DependSuffix) -MM menuefrage.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/josef/Programmieren/Codeblocks/METALL/FESTI/Festi5/Festi5/menuefrage.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/menuefrage.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/menuefrage.cpp$(PreprocessSuffix): menuefrage.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/menuefrage.cpp$(PreprocessSuffix) menuefrage.cpp

$(IntermediateDirectory)/menues.cpp$(ObjectSuffix): menues.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/menues.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/menues.cpp$(DependSuffix) -MM menues.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/josef/Programmieren/Codeblocks/METALL/FESTI/Festi5/Festi5/menues.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/menues.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/menues.cpp$(PreprocessSuffix): menues.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/menues.cpp$(PreprocessSuffix) menues.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


