solution "tllm"
language "C++"
configurations { "Debug", "Release" }
includedirs { "include", "src/include" }
files { "include/**.h" }

defines { "TLLM_BUILD" }

configuration "Debug"
defines { "DEBUG" }
flags { "Symbols" }
targetdir "build/debug"

configuration "Release"
defines { "NDEBUG" }
flags { "OptimizeSpeed",
	"ExtraWarnings",
	"FatalWarnings",
	"NoFramePointer" }
targetdir "build/release"

project "tllm"
kind "StaticLib"
files { "src/**.c", "src/**.cpp" }

project "tllm-dynamic"
kind "SharedLib"
files { "src/**.c", "src/**.cpp" }
targetname "tllm"

project "tests"
kind "ConsoleApp"
files { "tests/**.cpp" }
links { "tllm" }
configuration "Debug"
postbuildcommands("build/debug/tests")
configuration "Release"
postbuildcommands("build/release/tests")
