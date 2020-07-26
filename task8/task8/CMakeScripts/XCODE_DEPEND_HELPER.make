# DO NOT EDIT
# This makefile makes sure all linkable targets are
# up-to-date with anything they link to
default:
	echo "Do not invoke directly"

# Rules to remove targets that are older than anything to which they
# link.  This forces Xcode to relink the targets from scratch.  It
# does not seem to check these dependencies itself.
PostBuild.CGL.Debug:
/Users/lilin/repos/NotesForGraphics/task8works/task8/CGL/src/Debug/libCGL.a:
	/bin/rm -f /Users/lilin/repos/NotesForGraphics/task8works/task8/CGL/src/Debug/libCGL.a


PostBuild.glew.Debug:
/Users/lilin/repos/NotesForGraphics/task8works/task8/CGL/deps/glew/Debug/libglew.a:
	/bin/rm -f /Users/lilin/repos/NotesForGraphics/task8works/task8/CGL/deps/glew/Debug/libglew.a


PostBuild.glfw.Debug:
/Users/lilin/repos/NotesForGraphics/task8works/task8/CGL/deps/glfw/src/Debug/libglfw3.a:
	/bin/rm -f /Users/lilin/repos/NotesForGraphics/task8works/task8/CGL/deps/glfw/src/Debug/libglfw3.a


PostBuild.ropesim.Debug:
PostBuild.CGL.Debug: /Users/lilin/repos/NotesForGraphics/task8works/task8/Debug/ropesim
PostBuild.glew.Debug: /Users/lilin/repos/NotesForGraphics/task8works/task8/Debug/ropesim
PostBuild.glfw.Debug: /Users/lilin/repos/NotesForGraphics/task8works/task8/Debug/ropesim
/Users/lilin/repos/NotesForGraphics/task8works/task8/Debug/ropesim:\
	/Users/lilin/repos/NotesForGraphics/task8works/task8/CGL/src/Debug/libCGL.a\
	/Users/lilin/repos/NotesForGraphics/task8works/task8/CGL/deps/glew/Debug/libglew.a\
	/Users/lilin/repos/NotesForGraphics/task8works/task8/CGL/deps/glfw/src/Debug/libglfw3.a\
	/usr/local/lib/libfreetype.dylib\
	/usr/local/lib/libfreetype.dylib
	/bin/rm -f /Users/lilin/repos/NotesForGraphics/task8works/task8/Debug/ropesim


PostBuild.CGL.Release:
/Users/lilin/repos/NotesForGraphics/task8works/task8/CGL/src/Release/libCGL.a:
	/bin/rm -f /Users/lilin/repos/NotesForGraphics/task8works/task8/CGL/src/Release/libCGL.a


PostBuild.glew.Release:
/Users/lilin/repos/NotesForGraphics/task8works/task8/CGL/deps/glew/Release/libglew.a:
	/bin/rm -f /Users/lilin/repos/NotesForGraphics/task8works/task8/CGL/deps/glew/Release/libglew.a


PostBuild.glfw.Release:
/Users/lilin/repos/NotesForGraphics/task8works/task8/CGL/deps/glfw/src/Release/libglfw3.a:
	/bin/rm -f /Users/lilin/repos/NotesForGraphics/task8works/task8/CGL/deps/glfw/src/Release/libglfw3.a


PostBuild.ropesim.Release:
PostBuild.CGL.Release: /Users/lilin/repos/NotesForGraphics/task8works/task8/Release/ropesim
PostBuild.glew.Release: /Users/lilin/repos/NotesForGraphics/task8works/task8/Release/ropesim
PostBuild.glfw.Release: /Users/lilin/repos/NotesForGraphics/task8works/task8/Release/ropesim
/Users/lilin/repos/NotesForGraphics/task8works/task8/Release/ropesim:\
	/Users/lilin/repos/NotesForGraphics/task8works/task8/CGL/src/Release/libCGL.a\
	/Users/lilin/repos/NotesForGraphics/task8works/task8/CGL/deps/glew/Release/libglew.a\
	/Users/lilin/repos/NotesForGraphics/task8works/task8/CGL/deps/glfw/src/Release/libglfw3.a\
	/usr/local/lib/libfreetype.dylib\
	/usr/local/lib/libfreetype.dylib
	/bin/rm -f /Users/lilin/repos/NotesForGraphics/task8works/task8/Release/ropesim


PostBuild.CGL.MinSizeRel:
/Users/lilin/repos/NotesForGraphics/task8works/task8/CGL/src/MinSizeRel/libCGL.a:
	/bin/rm -f /Users/lilin/repos/NotesForGraphics/task8works/task8/CGL/src/MinSizeRel/libCGL.a


PostBuild.glew.MinSizeRel:
/Users/lilin/repos/NotesForGraphics/task8works/task8/CGL/deps/glew/MinSizeRel/libglew.a:
	/bin/rm -f /Users/lilin/repos/NotesForGraphics/task8works/task8/CGL/deps/glew/MinSizeRel/libglew.a


PostBuild.glfw.MinSizeRel:
/Users/lilin/repos/NotesForGraphics/task8works/task8/CGL/deps/glfw/src/MinSizeRel/libglfw3.a:
	/bin/rm -f /Users/lilin/repos/NotesForGraphics/task8works/task8/CGL/deps/glfw/src/MinSizeRel/libglfw3.a


PostBuild.ropesim.MinSizeRel:
PostBuild.CGL.MinSizeRel: /Users/lilin/repos/NotesForGraphics/task8works/task8/MinSizeRel/ropesim
PostBuild.glew.MinSizeRel: /Users/lilin/repos/NotesForGraphics/task8works/task8/MinSizeRel/ropesim
PostBuild.glfw.MinSizeRel: /Users/lilin/repos/NotesForGraphics/task8works/task8/MinSizeRel/ropesim
/Users/lilin/repos/NotesForGraphics/task8works/task8/MinSizeRel/ropesim:\
	/Users/lilin/repos/NotesForGraphics/task8works/task8/CGL/src/MinSizeRel/libCGL.a\
	/Users/lilin/repos/NotesForGraphics/task8works/task8/CGL/deps/glew/MinSizeRel/libglew.a\
	/Users/lilin/repos/NotesForGraphics/task8works/task8/CGL/deps/glfw/src/MinSizeRel/libglfw3.a\
	/usr/local/lib/libfreetype.dylib\
	/usr/local/lib/libfreetype.dylib
	/bin/rm -f /Users/lilin/repos/NotesForGraphics/task8works/task8/MinSizeRel/ropesim


PostBuild.CGL.RelWithDebInfo:
/Users/lilin/repos/NotesForGraphics/task8works/task8/CGL/src/RelWithDebInfo/libCGL.a:
	/bin/rm -f /Users/lilin/repos/NotesForGraphics/task8works/task8/CGL/src/RelWithDebInfo/libCGL.a


PostBuild.glew.RelWithDebInfo:
/Users/lilin/repos/NotesForGraphics/task8works/task8/CGL/deps/glew/RelWithDebInfo/libglew.a:
	/bin/rm -f /Users/lilin/repos/NotesForGraphics/task8works/task8/CGL/deps/glew/RelWithDebInfo/libglew.a


PostBuild.glfw.RelWithDebInfo:
/Users/lilin/repos/NotesForGraphics/task8works/task8/CGL/deps/glfw/src/RelWithDebInfo/libglfw3.a:
	/bin/rm -f /Users/lilin/repos/NotesForGraphics/task8works/task8/CGL/deps/glfw/src/RelWithDebInfo/libglfw3.a


PostBuild.ropesim.RelWithDebInfo:
PostBuild.CGL.RelWithDebInfo: /Users/lilin/repos/NotesForGraphics/task8works/task8/RelWithDebInfo/ropesim
PostBuild.glew.RelWithDebInfo: /Users/lilin/repos/NotesForGraphics/task8works/task8/RelWithDebInfo/ropesim
PostBuild.glfw.RelWithDebInfo: /Users/lilin/repos/NotesForGraphics/task8works/task8/RelWithDebInfo/ropesim
/Users/lilin/repos/NotesForGraphics/task8works/task8/RelWithDebInfo/ropesim:\
	/Users/lilin/repos/NotesForGraphics/task8works/task8/CGL/src/RelWithDebInfo/libCGL.a\
	/Users/lilin/repos/NotesForGraphics/task8works/task8/CGL/deps/glew/RelWithDebInfo/libglew.a\
	/Users/lilin/repos/NotesForGraphics/task8works/task8/CGL/deps/glfw/src/RelWithDebInfo/libglfw3.a\
	/usr/local/lib/libfreetype.dylib\
	/usr/local/lib/libfreetype.dylib
	/bin/rm -f /Users/lilin/repos/NotesForGraphics/task8works/task8/RelWithDebInfo/ropesim




# For each target create a dummy ruleso the target does not have to exist
/Users/lilin/repos/NotesForGraphics/task8works/task8/CGL/deps/glew/Debug/libglew.a:
/Users/lilin/repos/NotesForGraphics/task8works/task8/CGL/deps/glew/MinSizeRel/libglew.a:
/Users/lilin/repos/NotesForGraphics/task8works/task8/CGL/deps/glew/RelWithDebInfo/libglew.a:
/Users/lilin/repos/NotesForGraphics/task8works/task8/CGL/deps/glew/Release/libglew.a:
/Users/lilin/repos/NotesForGraphics/task8works/task8/CGL/deps/glfw/src/Debug/libglfw3.a:
/Users/lilin/repos/NotesForGraphics/task8works/task8/CGL/deps/glfw/src/MinSizeRel/libglfw3.a:
/Users/lilin/repos/NotesForGraphics/task8works/task8/CGL/deps/glfw/src/RelWithDebInfo/libglfw3.a:
/Users/lilin/repos/NotesForGraphics/task8works/task8/CGL/deps/glfw/src/Release/libglfw3.a:
/Users/lilin/repos/NotesForGraphics/task8works/task8/CGL/src/Debug/libCGL.a:
/Users/lilin/repos/NotesForGraphics/task8works/task8/CGL/src/MinSizeRel/libCGL.a:
/Users/lilin/repos/NotesForGraphics/task8works/task8/CGL/src/RelWithDebInfo/libCGL.a:
/Users/lilin/repos/NotesForGraphics/task8works/task8/CGL/src/Release/libCGL.a:
/usr/local/lib/libfreetype.dylib:
