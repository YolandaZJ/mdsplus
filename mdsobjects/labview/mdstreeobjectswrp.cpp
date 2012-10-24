#include "mdsobjectswrp.h"

using namespace MDSplus;

/********************************************************************************************************
												TREE
 ********************************************************************************************************/

DLLEXPORT void mdsplus_tree_addDevice(const void *lvTreePtr, void **lvTreeNodePtrOut, const char *nameIn, const char *typeIn, ErrorCluster *error)
{
	Tree *treePtr = NULL;
	TreeNode *treeNodePtrOut = NULL;
	MgErr errorCode = noErr;
	const char *errorSource = __FUNCTION__;
	char *errorMessage = "";
	try
	{
		treePtr = reinterpret_cast<Tree *>(const_cast<void *>(lvTreePtr));
		treeNodePtrOut = treePtr->addDevice(const_cast<char *>(nameIn), const_cast<char *>(typeIn));
		*lvTreeNodePtrOut = reinterpret_cast<void *>(treeNodePtrOut);
	}
	catch (MdsException *mdsE)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(mdsE->what());
	}
	catch (exception *e)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(e->what());
	}
	fillErrorCluster(errorCode, errorSource, errorMessage, error);
}

DLLEXPORT void mdsplus_tree_addNode(const void *lvTreePtr, void **lvTreeNodePtrOut, const char *nameIn, const char *usageIn, ErrorCluster *error)
{
	Tree *treePtr = NULL;
	TreeNode *treeNodePtrOut = NULL;
	MgErr errorCode = noErr;
	const char *errorSource = __FUNCTION__;
	char *errorMessage = "";
	try
	{
		treePtr = reinterpret_cast<Tree *>(const_cast<void *>(lvTreePtr));
		treeNodePtrOut = treePtr->addNode(const_cast<char *>(nameIn), const_cast<char *>(usageIn));
		*lvTreeNodePtrOut = reinterpret_cast<void *>(treeNodePtrOut);
	}
	catch (MdsException *mdsE)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(mdsE->what());
	}
	catch (exception *e)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(e->what());
	}
	fillErrorCluster(errorCode, errorSource, errorMessage, error);
}

DLLEXPORT void mdsplus_tree_constructor(void **lvTreePtrOut, const char *nameIn, int shotIn, ErrorCluster *error)
{
	Tree *treePtrOut = NULL;
	MgErr errorCode = noErr;
	const char *errorSource = __FUNCTION__;
	char *errorMessage = "";
	try
	{
		treePtrOut = new Tree(const_cast<char *>(nameIn), shotIn);
		*lvTreePtrOut = reinterpret_cast<void *>(treePtrOut);
	}
	catch (MdsException *mdsE)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(mdsE->what());
	}
	catch (exception *e)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(e->what());
	}
	fillErrorCluster(errorCode, errorSource, errorMessage, error);
}

DLLEXPORT void mdsplus_tree_constructor_mode(void **lvTreePtrOut, const char *nameIn, int shotIn, const char *modeIn, ErrorCluster *error)
{
	Tree *treePtrOut = NULL;
	MgErr errorCode = noErr;
	const char *errorSource = __FUNCTION__;
	char *errorMessage = "";
	try
	{
		treePtrOut = new Tree(const_cast<char *>(nameIn), shotIn, const_cast<char *>(modeIn));
		*lvTreePtrOut = reinterpret_cast<void *>(treePtrOut);
	}
	catch (MdsException *mdsE)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(mdsE->what());
	}
	catch (exception *e)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(e->what());
	}
	fillErrorCluster(errorCode, errorSource, errorMessage, error);
}

DLLEXPORT void mdsplus_tree_createPulse(const void *lvTreePtr, int shotIn, ErrorCluster *error)
{
	Tree *treePtr = NULL;
	MgErr errorCode = noErr;
	const char *errorSource = __FUNCTION__;
	char *errorMessage = "";
	try
	{
		treePtr = reinterpret_cast<Tree *>(const_cast<void *>(lvTreePtr));
		treePtr->createPulse(shotIn);
	}
	catch (MdsException *mdsE)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(mdsE->what());
	}
	catch (exception *e)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(e->what());
	}
	fillErrorCluster(errorCode, errorSource, errorMessage, error);
}

DLLEXPORT void mdsplus_tree_deletePulse(const void *lvTreePtr, int shotIn, ErrorCluster *error)
{
	Tree *treePtr = NULL;
	MgErr errorCode = noErr;
	const char *errorSource = __FUNCTION__;
	char *errorMessage = "";
	try
	{
		treePtr = reinterpret_cast<Tree *>(const_cast<void *>(lvTreePtr));
		treePtr->deletePulse(shotIn);
	}
	catch (MdsException *mdsE)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(mdsE->what());
	}
	catch (exception *e)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(e->what());
	}
	fillErrorCluster(errorCode, errorSource, errorMessage, error);
}

DLLEXPORT void mdsplus_tree_destructor(void **lvTreePtr)
{
	Tree *treePtr = reinterpret_cast<Tree *>(*lvTreePtr);
	delete treePtr;
	*lvTreePtr = NULL;
}

DLLEXPORT void mdsplus_tree_edit(const void *lvTreePtr, ErrorCluster *error)
{
	Tree *treePtr = NULL;
	MgErr errorCode = noErr;
	const char *errorSource = __FUNCTION__;
	char *errorMessage = "";
	try
	{
		treePtr = reinterpret_cast<Tree *>(const_cast<void *>(lvTreePtr));
		treePtr->edit();
	}
	catch (MdsException *mdsE)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(mdsE->what());
	}
	catch (exception *e)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(e->what());
	}
	fillErrorCluster(errorCode, errorSource, errorMessage, error);
}

DLLEXPORT void mdsplus_tree_findTags(const void *lvTreePtr, void **lvStringArrayPtrOut, const char *wildIn, ErrorCluster *error)
{
	Tree *treePtr = NULL;
	StringArray *stringArrayPtrOut = NULL;
	MgErr errorCode = noErr;
	const char *errorSource = __FUNCTION__;
	char *errorMessage = "";
	try
	{
		treePtr = reinterpret_cast<Tree *>(const_cast<void *>(lvTreePtr));
		stringArrayPtrOut = treePtr->findTags(const_cast<char *>(wildIn));
		*lvStringArrayPtrOut = reinterpret_cast<void *>(stringArrayPtrOut);
	}
	catch (exception *e)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(e->what());
	}
	fillErrorCluster(errorCode, errorSource, errorMessage, error);
}
/*
DLLEXPORT void mdsplus_tree_getActiveTree(void **lvTreePtrOut, ErrorCluster *error)
{
	Tree *treePtrOut = NULL;
	MgErr errorCode = noErr;
	const char *errorSource = __FUNCTION__;
	char *errorMessage = "";
	try
	{
		treePtrOut = getActiveTree();
		*lvTreePtrOut = reinterpret_cast<void *>(treePtrOut);
	}
	catch (MdsException *mdsE)
	{
		delete treePtrOut;
		errorCode = bogusError;
		errorMessage = const_cast<char *>(mdsE->what());
	}
	catch (exception *e)
	{
		delete treePtrOut;
		errorCode = bogusError;
		errorMessage = const_cast<char *>(e->what());
	}
	fillErrorCluster(errorCode, errorSource, errorMessage, error);
}
*/
DLLEXPORT void mdsplus_tree_getCurrent(int *currentOut, const char *treeNameIn, ErrorCluster *error)
{
	MgErr errorCode = noErr;
	const char *errorSource = __FUNCTION__;
	char *errorMessage = "";
	try
	{
		*currentOut = Tree::getCurrent(const_cast<char *>(treeNameIn));
	}
	catch (exception *e)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(e->what());
	}
	fillErrorCluster(errorCode, errorSource, errorMessage, error);
}

DLLEXPORT void mdsplus_tree_getDatafileSize(const void *lvTreePtr, _int64 *sizeOut, ErrorCluster *error)
{
	Tree *treePtr = NULL;
	MgErr errorCode = noErr;
	const char *errorSource = __FUNCTION__;
	char *errorMessage = "";
	try
	{
		treePtr = reinterpret_cast<Tree *>(const_cast<void *>(lvTreePtr));
		*sizeOut = treePtr->getDatafileSize();
	}
	catch (MdsException *mdsE)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(mdsE->what());
	}
	catch (exception *e)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(e->what());
	}
	fillErrorCluster(errorCode, errorSource, errorMessage, error);
}

DLLEXPORT void mdsplus_tree_getDefault(const void *lvTreePtr, void **lvTreeNodePtrOut, ErrorCluster *error)
{
	Tree *treePtr = NULL;
	TreeNode *treeNodePtrOut = NULL;
	MgErr errorCode = noErr;
	const char *errorSource = __FUNCTION__;
	char *errorMessage = "";
	try
	{
		treePtr = reinterpret_cast<Tree *>(const_cast<void *>(lvTreePtr));
		treeNodePtrOut = treePtr->getDefault();
		*lvTreeNodePtrOut = reinterpret_cast<void *>(treeNodePtrOut);
	}
	catch (MdsException *mdsE)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(mdsE->what());
	}
	catch (exception *e)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(e->what());
	}
	fillErrorCluster(errorCode, errorSource, errorMessage, error);
}

DLLEXPORT void mdsplus_tree_getNode(const void *lvTreePtr, void **lvTreeNodePtrOut, const char *pathIn, ErrorCluster *error)
{
	Tree *treePtr = NULL;
	TreeNode *treeNodePtrOut = NULL;
	MgErr errorCode = noErr;
	const char *errorSource = __FUNCTION__;
	char *errorMessage = "";
	try
	{
		treePtr = reinterpret_cast<Tree *>(const_cast<void *>(lvTreePtr));
		treeNodePtrOut = treePtr->getNode(const_cast<char *>(pathIn));
		*lvTreeNodePtrOut = reinterpret_cast<void *>(treeNodePtrOut);
	}
	catch (MdsException *mdsE)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(mdsE->what());
	}
	catch (exception *e)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(e->what());
	}
	fillErrorCluster(errorCode, errorSource, errorMessage, error);
}

DLLEXPORT void mdsplus_tree_getNode_string(const void *lvTreePtr, void **lvTreeNodePtrOut, const void *lvStringPtrIn, ErrorCluster *error)
{
	Tree *treePtr = NULL;
	TreeNode *treeNodePtrOut = NULL;
	MgErr errorCode = noErr;
	const char *errorSource = __FUNCTION__;
	char *errorMessage = "";
	try
	{
		treePtr = reinterpret_cast<Tree *>(const_cast<void *>(lvTreePtr));
		String *stringPtrIn = reinterpret_cast<String *>(const_cast<void *>(lvStringPtrIn));
		treeNodePtrOut = treePtr->getNode(stringPtrIn);
		*lvTreeNodePtrOut = reinterpret_cast<void *>(treeNodePtrOut);
	}
	catch (MdsException *mdsE)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(mdsE->what());
	}
	catch (exception *e)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(e->what());
	}
	fillErrorCluster(errorCode, errorSource, errorMessage, error);
}

DLLEXPORT void mdsplus_tree_getNode_treepath(const void *lvTreePtr, void **lvTreeNodePtrOut, const void *lvTreePathPtrIn, ErrorCluster *error)
{
	Tree *treePtr = NULL;
	TreeNode *treeNodePtrOut = NULL;
	MgErr errorCode = noErr;
	const char *errorSource = __FUNCTION__;
	char *errorMessage = "";
	try
	{
		treePtr = reinterpret_cast<Tree *>(const_cast<void *>(lvTreePtr));
		TreePath *treePathPtrIn = reinterpret_cast<TreePath *>(const_cast<void *>(lvTreePathPtrIn));
		treeNodePtrOut = treePtr->getNode(treePathPtrIn);
		*lvTreeNodePtrOut = reinterpret_cast<void *>(treeNodePtrOut);
	}
	catch (MdsException *mdsE)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(mdsE->what());
	}
	catch (exception *e)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(e->what());
	}
	fillErrorCluster(errorCode, errorSource, errorMessage, error);
}

DLLEXPORT void mdsplus_tree_getNodeWild(const void *lvTreePtr, void **lvTreeNodeArrayPtrOut, const char *pathIn, ErrorCluster *error)
{
	Tree *treePtr = NULL;
	TreeNodeArray *treeNodeArrayPtrOut = NULL;
	MgErr errorCode = noErr;
	const char *errorSource = __FUNCTION__;
	char *errorMessage = "";
	try
	{
		treePtr = reinterpret_cast<Tree *>(const_cast<void *>(lvTreePtr));
		treeNodeArrayPtrOut = treePtr->getNodeWild(const_cast<char *>(pathIn));
		*lvTreeNodeArrayPtrOut = reinterpret_cast<void *>(treeNodeArrayPtrOut);
	}
	catch (MdsException *mdsE)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(mdsE->what());
	}
	catch (exception *e)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(e->what());
	}
	fillErrorCluster(errorCode, errorSource, errorMessage, error);
}

DLLEXPORT void mdsplus_tree_getNodeWild_usageMask(const void *lvTreePtr, void **lvTreeNodeArrayPtrOut, const char *pathIn, int usageMaskIn, ErrorCluster *error)
{
	Tree *treePtr = NULL;
	TreeNodeArray *treeNodeArrayPtrOut = NULL;
	MgErr errorCode = noErr;
	const char *errorSource = __FUNCTION__;
	char *errorMessage = "";
	try
	{
		treePtr = reinterpret_cast<Tree *>(const_cast<void *>(lvTreePtr));
		treeNodeArrayPtrOut = treePtr->getNodeWild(const_cast<char *>(pathIn), usageMaskIn);
		*lvTreeNodeArrayPtrOut = reinterpret_cast<void *>(treeNodeArrayPtrOut);
	}
	catch (MdsException *mdsE)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(mdsE->what());
	}
	catch (exception *e)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(e->what());
	}
	fillErrorCluster(errorCode, errorSource, errorMessage, error);
}

DLLEXPORT void mdsplus_tree_isModified(const void *lvTreePtr, LVBoolean *lvIsModifiedOut, ErrorCluster *error)
{
	Tree *treePtr = NULL;
	MgErr errorCode = noErr;
	const char *errorSource = __FUNCTION__;
	char *errorMessage = "";
	try
	{
		treePtr = reinterpret_cast<Tree *>(const_cast<void *>(lvTreePtr));
		*lvIsModifiedOut = (treePtr->isModified() == true) ? LVBooleanTrue : LVBooleanFalse;
	}
	catch (MdsException *mdsE)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(mdsE->what());
	}
	catch (exception *e)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(e->what());
	}
	fillErrorCluster(errorCode, errorSource, errorMessage, error);
}

DLLEXPORT void mdsplus_tree_isOpenForEdit(const void *lvTreePtr, LVBoolean *lvIsOpenForEditOut, ErrorCluster *error)
{
	Tree *treePtr = NULL;
	MgErr errorCode = noErr;
	const char *errorSource = __FUNCTION__;
	char *errorMessage = "";
	try
	{
		treePtr = reinterpret_cast<Tree *>(const_cast<void *>(lvTreePtr));
		*lvIsOpenForEditOut = (treePtr->isOpenForEdit() == true) ? LVBooleanTrue : LVBooleanFalse;
	}
	catch (MdsException *mdsE)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(mdsE->what());
	}
	catch (exception *e)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(e->what());
	}
	fillErrorCluster(errorCode, errorSource, errorMessage, error);
}

DLLEXPORT void mdsplus_tree_isReadOnly(const void *lvTreePtr, LVBoolean *lvIsReadOnlyOut, ErrorCluster *error)
{
	Tree *treePtr = NULL;
	MgErr errorCode = noErr;
	const char *errorSource = __FUNCTION__;
	char *errorMessage = "";
	try
	{
		treePtr = reinterpret_cast<Tree *>(const_cast<void *>(lvTreePtr));
		*lvIsReadOnlyOut = (treePtr->isReadOnly() == true) ? LVBooleanTrue : LVBooleanFalse;
	}
	catch (MdsException *mdsE)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(mdsE->what());
	}
	catch (exception *e)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(e->what());
	}
	fillErrorCluster(errorCode, errorSource, errorMessage, error);
}

DLLEXPORT void mdsplus_tree_quit(const void *lvTreePtr, ErrorCluster *error)
{
	Tree *treePtr = NULL;
	MgErr errorCode = noErr;
	const char *errorSource = __FUNCTION__;
	char *errorMessage = "";
	try
	{
		treePtr = reinterpret_cast<Tree *>(const_cast<void *>(lvTreePtr));
		treePtr->quit();
	}
	catch (MdsException *mdsE)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(mdsE->what());
	}
	catch (exception *e)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(e->what());
	}
	fillErrorCluster(errorCode, errorSource, errorMessage, error);
}

DLLEXPORT void mdsplus_tree_remove(const void *lvTreePtr, const char *nameIn, ErrorCluster *error)
{
	Tree *treePtr = NULL;
	MgErr errorCode = noErr;
	const char *errorSource = __FUNCTION__;
	char *errorMessage = "";
	try
	{
		treePtr = reinterpret_cast<Tree *>(const_cast<void *>(lvTreePtr));
		treePtr->remove(const_cast<char *>(nameIn));
	}
	catch (MdsException *mdsE)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(mdsE->what());
	}
	catch (exception *e)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(e->what());
	}
	fillErrorCluster(errorCode, errorSource, errorMessage, error);
}

DLLEXPORT void mdsplus_tree_removeTag(const void *lvTreePtr, const char *tagNameIn, ErrorCluster *error)
{
	Tree *treePtr = NULL;
	MgErr errorCode = noErr;
	const char *errorSource = __FUNCTION__;
	char *errorMessage = "";
	try
	{
		treePtr = reinterpret_cast<Tree *>(const_cast<void *>(lvTreePtr));
		treePtr->removeTag(const_cast<char *>(tagNameIn));
	}
	catch (MdsException *mdsE)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(mdsE->what());
	}
	catch (exception *e)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(e->what());
	}
	fillErrorCluster(errorCode, errorSource, errorMessage, error);
}

/*DLLEXPORT void mdsplus_tree_setActiveTree(const void *lvTreePtrIn, ErrorCluster *error)
{
	Tree *treePtrIn = NULL;
	MgErr errorCode = noErr;
	const char *errorSource = __FUNCTION__;
	char *errorMessage = "";
	try
	{
		treePtrIn = reinterpret_cast<Tree *>(const_cast<void *>(lvTreePtrIn));
		setActiveTree(treePtrIn);
	}
	catch (exception *e)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(e->what());
	}
	fillErrorCluster(errorCode, errorSource, errorMessage, error);
}
*/
DLLEXPORT void mdsplus_tree_setCurrent(const char *treeNameIn, int shotIn, ErrorCluster *error)
{
	MgErr errorCode = noErr;
	const char *errorSource = __FUNCTION__;
	char *errorMessage = "";
	try
	{
		Tree::setCurrent(const_cast<char *>(treeNameIn), shotIn);
	}
	catch (MdsException *mdsE)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(mdsE->what());
	}
	catch (exception *e)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(e->what());
	}
	fillErrorCluster(errorCode, errorSource, errorMessage, error);
}

DLLEXPORT void mdsplus_tree_setDefault(const void *lvTreePtr, const void *lvTreeNodePtrIn, ErrorCluster *error)
{
	Tree *treePtr = NULL;
	TreeNode *treeNodePtrIn = NULL;
	MgErr errorCode = noErr;
	const char *errorSource = __FUNCTION__;
	char *errorMessage = "";
	try
	{
		treePtr = reinterpret_cast<Tree *>(const_cast<void *>(lvTreePtr));
		treeNodePtrIn = reinterpret_cast<TreeNode *>(const_cast<void *>(lvTreeNodePtrIn));
		treePtr->setDefault(treeNodePtrIn);
	}
	catch (MdsException *mdsE)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(mdsE->what());
	}
	catch (exception *e)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(e->what());
	}
	fillErrorCluster(errorCode, errorSource, errorMessage, error);
}

DLLEXPORT void mdsplus_tree_setTimeContext(const void *lvTreePtr, const void *lvStartDataPtrIn, const void *lvEndDataPtrIn, const void *lvDeltaDataPtrIn, ErrorCluster *error)
{
	Tree *treePtr = NULL;
	Data *startDataPtrIn = NULL;
	Data *endDataPtrIn = NULL;
	Data *deltaDataPtrIn = NULL;
	MgErr errorCode = noErr;
	const char *errorSource = __FUNCTION__;
	char *errorMessage = "";
	try
	{
		treePtr = reinterpret_cast<Tree *>(const_cast<void *>(lvTreePtr));
		startDataPtrIn = reinterpret_cast<Data *>(const_cast<void *>(lvStartDataPtrIn));
		endDataPtrIn = reinterpret_cast<Data *>(const_cast<void *>(lvEndDataPtrIn));
		deltaDataPtrIn = reinterpret_cast<Data *>(const_cast<void *>(lvDeltaDataPtrIn));
		treePtr->setTimeContext(startDataPtrIn, endDataPtrIn, deltaDataPtrIn);
	}
	catch (MdsException *mdsE)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(mdsE->what());
	}
	catch (exception *e)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(e->what());
	}
	fillErrorCluster(errorCode, errorSource, errorMessage, error);
}

DLLEXPORT void mdsplus_tree_setVersionsInModel(const void *lvTreePtr, LVBoolean *lvVerEnabledIn, ErrorCluster *error)
{
	Tree *treePtr = NULL;
	bool verEnabledIn;
	MgErr errorCode = noErr;
	const char *errorSource = __FUNCTION__;
	char *errorMessage = "";
	try
	{
		treePtr = reinterpret_cast<Tree *>(const_cast<void *>(lvTreePtr));
		verEnabledIn = (*lvVerEnabledIn == LVBooleanTrue) ? true : false;
		treePtr->setVersionsInModel(verEnabledIn);
	}
	catch (MdsException *mdsE)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(mdsE->what());
	}
	catch (exception *e)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(e->what());
	}
	fillErrorCluster(errorCode, errorSource, errorMessage, error);
}

DLLEXPORT void mdsplus_tree_setVersionsInPulse(const void *lvTreePtr, LVBoolean *lvVerEnabledIn, ErrorCluster *error)
{
	Tree *treePtr = NULL;
	bool verEnabledIn;
	MgErr errorCode = noErr;
	const char *errorSource = __FUNCTION__;
	char *errorMessage = "";
	try
	{
		treePtr = reinterpret_cast<Tree *>(const_cast<void *>(lvTreePtr));
		verEnabledIn = (*lvVerEnabledIn == LVBooleanTrue) ? true : false;
		treePtr->setVersionsInPulse(verEnabledIn);
	}
	catch (MdsException *mdsE)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(mdsE->what());
	}
	catch (exception *e)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(e->what());
	}
	fillErrorCluster(errorCode, errorSource, errorMessage, error);
}

DLLEXPORT void mdsplus_tree_setViewDate(const void *lvTreePtr, const char *dateIn, ErrorCluster *error)
{
	Tree *treePtr = NULL;
	MgErr errorCode = noErr;
	const char *errorSource = __FUNCTION__;
	char *errorMessage = "";
	try
	{
		treePtr = reinterpret_cast<Tree *>(const_cast<void *>(lvTreePtr));
		treePtr->setViewDate(const_cast<char *>(dateIn));
	}
	catch (MdsException *mdsE)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(mdsE->what());
	}
	catch (exception *e)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(e->what());
	}
	fillErrorCluster(errorCode, errorSource, errorMessage, error);
}

DLLEXPORT void mdsplus_tree_versionsInModelEnabled(const void *lvTreePtr, LVBoolean *lvVerEnabledOut, ErrorCluster *error)
{
	Tree *treePtr = NULL;
	bool verEnabledOut;
	MgErr errorCode = noErr;
	const char *errorSource = __FUNCTION__;
	char *errorMessage = "";
	try
	{
		treePtr = reinterpret_cast<Tree *>(const_cast<void *>(lvTreePtr));
		verEnabledOut = treePtr->versionsInModelEnabled();
		*lvVerEnabledOut = (verEnabledOut == true) ? LVBooleanTrue : LVBooleanFalse;
	}
	catch (MdsException *mdsE)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(mdsE->what());
	}
	catch (exception *e)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(e->what());
	}
	fillErrorCluster(errorCode, errorSource, errorMessage, error);
}

DLLEXPORT void mdsplus_tree_versionsInPulseEnabled(const void *lvTreePtr, LVBoolean *lvVerEnabledOut, ErrorCluster *error)
{
	Tree *treePtr = NULL;
	bool verEnabledOut;
	MgErr errorCode = noErr;
	const char *errorSource = __FUNCTION__;
	char *errorMessage = "";
	try
	{
		treePtr = reinterpret_cast<Tree *>(const_cast<void *>(lvTreePtr));
		verEnabledOut = treePtr->versionsInPulseEnabled();
		*lvVerEnabledOut = (verEnabledOut == true) ? LVBooleanTrue : LVBooleanFalse;
	}
	catch (MdsException *mdsE)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(mdsE->what());
	}
	catch (exception *e)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(e->what());
	}
	fillErrorCluster(errorCode, errorSource, errorMessage, error);
}

DLLEXPORT void mdsplus_tree_write(const void *lvTreePtr, ErrorCluster *error)
{
	Tree *treePtr = NULL;
	MgErr errorCode = noErr;
	const char *errorSource = __FUNCTION__;
	char *errorMessage = "";
	try
	{
		treePtr = reinterpret_cast<Tree *>(const_cast<void *>(lvTreePtr));
		treePtr->write();
	}
	catch (MdsException *mdsE)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(mdsE->what());
	}
	catch (exception *e)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(e->what());
	}
	fillErrorCluster(errorCode, errorSource, errorMessage, error);
}

/********************************************************************************************************
												TREENODE
 ********************************************************************************************************/

DLLEXPORT void mdsplus_treenode_addDevice(const void *lvTreeNodePtr, void **lvTreeNodePtrOut, const char *nameIn, const char *typeIn, ErrorCluster *error)
{
	TreeNode *treeNodePtr = NULL;
	TreeNode *treeNodePtrOut = NULL;
	MgErr errorCode = noErr;
	const char *errorSource = __FUNCTION__;
	char *errorMessage = "";
	try
	{
		treeNodePtr = reinterpret_cast<TreeNode *>(const_cast<void *>(lvTreeNodePtr));
		treeNodePtrOut = treeNodePtr->addDevice(const_cast<char *>(nameIn), const_cast<char *>(typeIn));
		*lvTreeNodePtrOut = reinterpret_cast<void *>(treeNodePtrOut);
	}
	catch (MdsException *mdsE)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(mdsE->what());
	}
	catch (exception *e)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(e->what());
	}
	fillErrorCluster(errorCode, errorSource, errorMessage, error);
}

DLLEXPORT void mdsplus_treenode_addNode(const void *lvTreeNodePtr, void **lvTreeNodePtrOut, const char *nameIn, const char *usageIn, ErrorCluster *error)
{
	TreeNode *treeNodePtr = NULL;
	TreeNode *treeNodePtrOut = NULL;
	MgErr errorCode = noErr;
	const char *errorSource = __FUNCTION__;
	char *errorMessage = "";
	try
	{
		treeNodePtr = reinterpret_cast<TreeNode *>(const_cast<void *>(lvTreeNodePtr));
		treeNodePtrOut = treeNodePtr->addNode(const_cast<char *>(nameIn), const_cast<char *>(usageIn));
		*lvTreeNodePtrOut = reinterpret_cast<void *>(treeNodePtrOut);
	}
	catch (MdsException *mdsE)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(mdsE->what());
	}
	catch (exception *e)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(e->what());
	}
	fillErrorCluster(errorCode, errorSource, errorMessage, error);
}

DLLEXPORT void mdsplus_treenode_addTag(const void *lvTreeNodePtr, const char *tagNameIn, ErrorCluster *error)
{
	TreeNode *treeNodePtr = NULL;
	MgErr errorCode = noErr;
	const char *errorSource = __FUNCTION__;
	char *errorMessage = "";
	try
	{
		treeNodePtr = reinterpret_cast<TreeNode *>(const_cast<void *>(lvTreeNodePtr));
		treeNodePtr->addTag(const_cast<char *>(tagNameIn));
	}
	catch (MdsException *mdsE)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(mdsE->what());
	}
	catch (exception *e)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(e->what());
	}
	fillErrorCluster(errorCode, errorSource, errorMessage, error);
}

DLLEXPORT void mdsplus_treenode_beginSegment(const void *lvTreeNodePtr, const void *lvStartDataPtrIn, const void *lvEndDataPtrIn, const void *lvTimeDataPtrIn, const void *lvArrayPtrIn, ErrorCluster *error)
{
	TreeNode *treeNodePtr = NULL;
	Data *startDataPtrIn = NULL;
	Data *endDataPtrIn = NULL;
	Data *timeDataPtrIn = NULL;
	Array *initialDataArrayPtrIn = NULL;
	MgErr errorCode = noErr;
	const char *errorSource = __FUNCTION__;
	char *errorMessage = "";
	try
	{
		treeNodePtr = reinterpret_cast<TreeNode *>(const_cast<void *>(lvTreeNodePtr));
		startDataPtrIn = reinterpret_cast<Data *>(const_cast<void *>(lvStartDataPtrIn));
		endDataPtrIn = reinterpret_cast<Data *>(const_cast<void *>(lvEndDataPtrIn));
		timeDataPtrIn = reinterpret_cast<Data *>(const_cast<void *>(lvTimeDataPtrIn));
		initialDataArrayPtrIn = reinterpret_cast<Array *>(const_cast<void *>(lvArrayPtrIn));
		treeNodePtr->beginSegment(startDataPtrIn, endDataPtrIn, timeDataPtrIn, initialDataArrayPtrIn);
	}
	catch (MdsException *mdsE)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(mdsE->what());
	}
	catch (exception *e)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(e->what());
	}
	fillErrorCluster(errorCode, errorSource, errorMessage, error);
}

DLLEXPORT void mdsplus_treenode_beginTimestampedSegment(const void *lvTreeNodePtr, const void *lvArrayPtrIn, ErrorCluster *error)
{
	TreeNode *treeNodePtr = NULL;
	Array *initDataArrayPtrIn = NULL;
	MgErr errorCode = noErr;
	const char *errorSource = __FUNCTION__;
	char *errorMessage = "";
	try
	{
		treeNodePtr = reinterpret_cast<TreeNode *>(const_cast<void *>(lvTreeNodePtr));
		initDataArrayPtrIn = reinterpret_cast<Array *>(const_cast<void *>(lvArrayPtrIn));
		treeNodePtr->beginTimestampedSegment(initDataArrayPtrIn);
	}
	catch (MdsException *mdsE)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(mdsE->what());
	}
	catch (exception *e)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(e->what());
	}
	fillErrorCluster(errorCode, errorSource, errorMessage, error);
}

DLLEXPORT void mdsplus_treenode_containsVersions(const void *lvTreeNodePtr, LVBoolean *lvContainsVersionsOut, ErrorCluster *error)
{
	TreeNode *treeNodePtr = NULL;
	MgErr errorCode = noErr;
	const char *errorSource = __FUNCTION__;
	char *errorMessage = "";
	try
	{
		treeNodePtr = reinterpret_cast<TreeNode *>(const_cast<void *>(lvTreeNodePtr));
		*lvContainsVersionsOut = (treeNodePtr->containsVersions() == true) ? LVBooleanTrue : LVBooleanFalse;
	}
	catch (MdsException *mdsE)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(mdsE->what());
	}
	catch (exception *e)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(e->what());
	}
	fillErrorCluster(errorCode, errorSource, errorMessage, error);
}

DLLEXPORT void mdsplus_treenode_deleteData(const void *lvTreeNodePtr, ErrorCluster *error)
{
	TreeNode *treeNodePtr = NULL;
	MgErr errorCode = noErr;
	const char *errorSource = __FUNCTION__;
	char *errorMessage = "";
	try
	{
		treeNodePtr = reinterpret_cast<TreeNode *>(const_cast<void *>(lvTreeNodePtr));
		treeNodePtr->deleteData();
	}
	catch (MdsException *mdsE)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(mdsE->what());
	}
	catch (exception *e)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(e->what());
	}
	fillErrorCluster(errorCode, errorSource, errorMessage, error);
}

DLLEXPORT void mdsplus_treenode_doMethod(const void *lvTreeNodePtr, const char *methodIn, ErrorCluster *error)
{
	TreeNode *treeNodePtr = NULL;
	MgErr errorCode = noErr;
	const char *errorSource = __FUNCTION__;
	char *errorMessage = "";
	try
	{
		treeNodePtr = reinterpret_cast<TreeNode *>(const_cast<void *>(lvTreeNodePtr));
		treeNodePtr->doMethod(const_cast<char *>(methodIn));
	}
	catch (MdsException *mdsE)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(mdsE->what());
	}
	catch (exception *e)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(e->what());
	}
	fillErrorCluster(errorCode, errorSource, errorMessage, error);
}

DLLEXPORT void mdsplus_treenode_destructor(void **lvTreeNodePtr)
{
	TreeNode *treeNodePtr = reinterpret_cast<TreeNode *>(*lvTreeNodePtr);
	delete treeNodePtr;
	*lvTreeNodePtr = NULL;
}

DLLEXPORT void mdsplus_treenode_findTags(const void *lvTreeNodePtr, void **lvStringArrayPtrOut, ErrorCluster *error)
{
	TreeNode *treeNodePtr = NULL;
	StringArray *stringArrayPtrOut = NULL;
	MgErr errorCode = noErr;
	const char *errorSource = __FUNCTION__;
	char *errorMessage = "";
	try
	{
		treeNodePtr = reinterpret_cast<TreeNode *>(const_cast<void *>(lvTreeNodePtr));
		stringArrayPtrOut = treeNodePtr->findTags();
		*lvStringArrayPtrOut = reinterpret_cast<void *>(stringArrayPtrOut);
	}
	catch (exception *e)
	{
		delete stringArrayPtrOut;
		errorCode = bogusError;
		errorMessage = const_cast<char *>(e->what());
	}
	fillErrorCluster(errorCode, errorSource, errorMessage, error);
}

DLLEXPORT void mdsplus_treenode_getBrother(const void *lvTreeNodePtr, void **lvTreeNodePtrOut, ErrorCluster *error)
{
	TreeNode *treeNodePtr = NULL;
	TreeNode *treeNodePtrOut = NULL;
	MgErr errorCode = noErr;
	const char *errorSource = __FUNCTION__;
	char *errorMessage = "";
	try
	{
		treeNodePtr = reinterpret_cast<TreeNode *>(const_cast<void *>(lvTreeNodePtr));
		treeNodePtrOut = treeNodePtr->getBrother();
		*lvTreeNodePtrOut = reinterpret_cast<void *>(treeNodePtrOut);
	}
	catch (MdsException *mdsE)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(mdsE->what());
	}
	catch (exception *e)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(e->what());
	}
	fillErrorCluster(errorCode, errorSource, errorMessage, error);
}

DLLEXPORT void mdsplus_treenode_getChild(const void *lvTreeNodePtr, void **lvTreeNodePtrOut, ErrorCluster *error)
{
	TreeNode *treeNodePtr = NULL;
	TreeNode *treeNodePtrOut = NULL;
	MgErr errorCode = noErr;
	const char *errorSource = __FUNCTION__;
	char *errorMessage = "";
	try
	{
		treeNodePtr = reinterpret_cast<TreeNode *>(const_cast<void *>(lvTreeNodePtr));
		treeNodePtrOut = treeNodePtr->getChild();
		*lvTreeNodePtrOut = reinterpret_cast<void *>(treeNodePtrOut);
	}
	catch (MdsException *mdsE)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(mdsE->what());
	}
	catch (exception *e)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(e->what());
	}
	fillErrorCluster(errorCode, errorSource, errorMessage, error);
}

DLLEXPORT void mdsplus_treenode_getChildren(const void *lvTreeNodePtr, LPtrArrHdl lvPtrArrHdlOut, ErrorCluster *error)
{
	TreeNode *treeNodePtr = NULL;
	TreeNode **childrenArrOut;
	int childrenArrLen = 0;
	MgErr errorCode = noErr;
	const char *errorSource = __FUNCTION__;
	char *errorMessage = "";
	try
	{
		treeNodePtr = reinterpret_cast<TreeNode *>(const_cast<void *>(lvTreeNodePtr));
		childrenArrOut = treeNodePtr->getChildren(&childrenArrLen);
		// checks whether the size of a pointer is 32 bit or 64 bit depending upon the system architecture
		int32 typeCode = (sizeof(void *) > sizeof(int32)) ? iQ : iL;
		// resizes treenode array
		errorCode = NumericArrayResize(typeCode, 1, reinterpret_cast<UHandle *>(&lvPtrArrHdlOut), static_cast<int32>(childrenArrLen));
		if (!errorCode)
		{
			for (int i = 0; i < childrenArrLen; i++)
				(*lvPtrArrHdlOut)->elt[i] = static_cast<void *>(childrenArrOut[i]);
			(*lvPtrArrHdlOut)->dimSize = static_cast<int32>(childrenArrLen);
		}
		else
			errorMessage = "NumericArrayResize error";
		deleteNativeArray(reinterpret_cast<Data **>(childrenArrOut));
	}
	catch (MdsException *mdsE)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(mdsE->what());
	}
	catch (exception *e)
	{
		deleteNativeArray(reinterpret_cast<Data **>(childrenArrOut));
		errorCode = bogusError;
		errorMessage = const_cast<char *>(e->what());
	}
	fillErrorCluster(errorCode, errorSource, errorMessage, error);
}

DLLEXPORT void mdsplus_treenode_getClass(const void *lvTreeNodePtr, LStrHandle lvStrHdlOut, ErrorCluster *error)
{
	TreeNode *treeNodePtr = NULL;
	char *strOut = NULL;
	MgErr errorCode = noErr;
	const char *errorSource = __FUNCTION__;
	char *errorMessage = "";
	try
	{
		treeNodePtr = reinterpret_cast<TreeNode *>(const_cast<void *>(lvTreeNodePtr));
		strOut = const_cast<char *>(treeNodePtr->getClass());
		int32 strOutLen = static_cast<int32>(strlen(strOut));
		errorCode = NumericArrayResize(uB, 1, reinterpret_cast<UHandle *>(&lvStrHdlOut), strOutLen);
		if (!errorCode)
		{
			MoveBlock(reinterpret_cast<uChar *>(strOut), LStrBuf(*lvStrHdlOut), strOutLen);
			(*lvStrHdlOut)->cnt = strOutLen;
		}
		else
			errorMessage = "NumericArrayResize error";
		deleteString(strOut);
	}
	catch (MdsException *mdsE)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(mdsE->what());
	}
	catch (exception *e)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(e->what());
	}
	fillErrorCluster(errorCode, errorSource, errorMessage, error);
}

DLLEXPORT void mdsplus_treenode_getCompressedLength(const void *lvTreeNodePtr, int *compressedLengthOut, ErrorCluster *error)
{
	TreeNode *treeNodePtr = NULL;
	MgErr errorCode = noErr;
	const char *errorSource = __FUNCTION__;
	char *errorMessage = "";
	try
	{
		treeNodePtr = reinterpret_cast<TreeNode *>(const_cast<void *>(lvTreeNodePtr));
		*compressedLengthOut = treeNodePtr->getCompressedLength();
	}
	catch (MdsException *mdsE)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(mdsE->what());
	}
	catch (exception *e)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(e->what());
	}
	fillErrorCluster(errorCode, errorSource, errorMessage, error);
}

DLLEXPORT void mdsplus_treenode_getConglomerateElt(const void *lvTreeNodePtr, int *conglomerateEltOut, ErrorCluster *error)
{
	TreeNode *treeNodePtr = NULL;
	MgErr errorCode = noErr;
	const char *errorSource = __FUNCTION__;
	char *errorMessage = "";
	try
	{
		treeNodePtr = reinterpret_cast<TreeNode *>(const_cast<void *>(lvTreeNodePtr));
		*conglomerateEltOut = treeNodePtr->getConglomerateElt();
	}
	catch (MdsException *mdsE)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(mdsE->what());
	}
	catch (exception *e)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(e->what());
	}
	fillErrorCluster(errorCode, errorSource, errorMessage, error);
}

DLLEXPORT void mdsplus_treenode_getConglomerateNodes(const void *lvTreeNodePtr, void **lvTreeNodeArrayPtrOut, ErrorCluster *error)
{
	TreeNode *treeNodePtr = NULL;
	TreeNodeArray *treeNodeArrayPtrOut = NULL;
	MgErr errorCode = noErr;
	const char *errorSource = __FUNCTION__;
	char *errorMessage = "";
	try
	{
		treeNodePtr = reinterpret_cast<TreeNode *>(const_cast<void *>(lvTreeNodePtr));
		treeNodeArrayPtrOut = treeNodePtr->getConglomerateNodes();
		*lvTreeNodeArrayPtrOut = reinterpret_cast<void *>(treeNodeArrayPtrOut);
	}
	catch (MdsException *mdsE)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(mdsE->what());
	}
	catch (exception *e)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(e->what());
	}
	fillErrorCluster(errorCode, errorSource, errorMessage, error);
}

DLLEXPORT void mdsplus_treenode_getDepth(const void *lvTreeNodePtr, int *depthOut, ErrorCluster *error)
{
	TreeNode *treeNodePtr = NULL;
	MgErr errorCode = noErr;
	const char *errorSource = __FUNCTION__;
	char *errorMessage = "";
	try
	{
		treeNodePtr = reinterpret_cast<TreeNode *>(const_cast<void *>(lvTreeNodePtr));
		*depthOut = treeNodePtr->getDepth();
	}
	catch (MdsException *mdsE)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(mdsE->what());
	}
	catch (exception *e)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(e->what());
	}
	fillErrorCluster(errorCode, errorSource, errorMessage, error);
}

DLLEXPORT void mdsplus_treenode_getData(const void *lvTreeNodePtr, void **lvDataPtrOut, ErrorCluster *error)
{
	TreeNode *treeNodePtr = NULL;
	Data *dataPtrOut = NULL;
	MgErr errorCode = noErr;
	const char *errorSource = __FUNCTION__;
	char *errorMessage = "";
	try
	{
		treeNodePtr = reinterpret_cast<TreeNode *>(const_cast<void *>(lvTreeNodePtr));
		dataPtrOut = treeNodePtr->getData();
		*lvDataPtrOut = reinterpret_cast<void *>(dataPtrOut);
	}
	catch (MdsException *mdsE)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(mdsE->what());
	}
	catch (exception *e)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(e->what());
	}
	fillErrorCluster(errorCode, errorSource, errorMessage, error);
}

DLLEXPORT void mdsplus_treenode_getDescendants(const void *lvTreeNodePtr, LPtrArrHdl lvPtrArrHdlOut, ErrorCluster *error)
{
	TreeNode *treeNodePtr = NULL;
	TreeNode **descendantsArrOut;
	int descendantsArrLen = 0;
	MgErr errorCode = noErr;
	const char *errorSource = __FUNCTION__;
	char *errorMessage = "";
	try
	{
		treeNodePtr = reinterpret_cast<TreeNode *>(const_cast<void *>(lvTreeNodePtr));
		descendantsArrOut = treeNodePtr->getDescendants(&descendantsArrLen);
		// checks whether the size of a pointer is 32 bit or 64 bit depending upon the system architecture
		int32 typeCode = (sizeof(void *) > sizeof(int32)) ? iQ : iL;
		// resizes treenode array
		errorCode = NumericArrayResize(typeCode, 1, reinterpret_cast<UHandle *>(&lvPtrArrHdlOut), static_cast<int32>(descendantsArrLen));
		if (!errorCode)
		{
			for (int i = 0; i < descendantsArrLen; i++)
				(*lvPtrArrHdlOut)->elt[i] = static_cast<void *>(descendantsArrOut[i]);
			(*lvPtrArrHdlOut)->dimSize = static_cast<int32>(descendantsArrLen);
		}
		else
			errorMessage = "NumericArrayResize error";
		deleteNativeArray(reinterpret_cast<Data **>(descendantsArrOut));
	}
	catch (MdsException *mdsE)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(mdsE->what());
	}
	catch (exception *e)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(e->what());
	}
	fillErrorCluster(errorCode, errorSource, errorMessage, error);
}

DLLEXPORT void mdsplus_treenode_getDType(const void *lvTreeNodePtr, LStrHandle lvStrHdlOut, ErrorCluster *error)
{
	TreeNode *treeNodePtr = NULL;
	char *strOut = NULL;
	MgErr errorCode = noErr;
	const char *errorSource = __FUNCTION__;
	char *errorMessage = "";
	try
	{
		treeNodePtr = reinterpret_cast<TreeNode *>(const_cast<void *>(lvTreeNodePtr));
		strOut = const_cast<char *>(treeNodePtr->getDType());
		int32 strOutLen = static_cast<int32>(strlen(strOut));
		errorCode = NumericArrayResize(uB, 1, reinterpret_cast<UHandle *>(&lvStrHdlOut), strOutLen);
		if (!errorCode)
		{
			MoveBlock(reinterpret_cast<uChar *>(strOut), LStrBuf(*lvStrHdlOut), strOutLen);
			(*lvStrHdlOut)->cnt = strOutLen;
		}
		else
			errorMessage = "NumericArrayResize error";
		deleteString(strOut);
	}
	catch (MdsException *mdsE)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(mdsE->what());
	}
	catch (exception *e)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(e->what());
	}
	fillErrorCluster(errorCode, errorSource, errorMessage, error);
}

DLLEXPORT void mdsplus_treenode_getFullPath(const void *lvTreeNodePtr, LStrHandle lvStrHdlOut, ErrorCluster *error)
{
	TreeNode *treeNodePtr = NULL;
	char *strOut = NULL;
	MgErr errorCode = noErr;
	const char *errorSource = __FUNCTION__;
	char *errorMessage = "";
	try
	{
		treeNodePtr = reinterpret_cast<TreeNode *>(const_cast<void *>(lvTreeNodePtr));
		strOut = treeNodePtr->getFullPath();
		int32 strOutLen = static_cast<int32>(strlen(strOut));
		errorCode = NumericArrayResize(uB, 1, reinterpret_cast<UHandle *>(&lvStrHdlOut), strOutLen);
		if (!errorCode)
		{
			MoveBlock(reinterpret_cast<uChar *>(strOut), LStrBuf(*lvStrHdlOut), strOutLen);
			(*lvStrHdlOut)->cnt = strOutLen;
		}
		else
			errorMessage = "NumericArrayResize error";
		deleteString(strOut);
	}
	catch (MdsException *mdsE)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(mdsE->what());
	}
	catch (exception *e)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(e->what());
	}
	fillErrorCluster(errorCode, errorSource, errorMessage, error);
}

DLLEXPORT void mdsplus_treenode_getLength(const void *lvTreeNodePtr, int *lengthOut, ErrorCluster *error)
{
	TreeNode *treeNodePtr = NULL;
	MgErr errorCode = noErr;
	const char *errorSource = __FUNCTION__;
	char *errorMessage = "";
	try
	{
		treeNodePtr = reinterpret_cast<TreeNode *>(const_cast<void *>(lvTreeNodePtr));
		*lengthOut = treeNodePtr->getLength();
	}
	catch (MdsException *mdsE)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(mdsE->what());
	}
	catch (exception *e)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(e->what());
	}
	fillErrorCluster(errorCode, errorSource, errorMessage, error);
}

DLLEXPORT void mdsplus_treenode_getMember(const void *lvTreeNodePtr, void **lvTreeNodePtrOut, ErrorCluster *error)
{
	TreeNode *treeNodePtr = NULL;
	TreeNode *treeNodePtrOut = NULL;
	MgErr errorCode = noErr;
	const char *errorSource = __FUNCTION__;
	char *errorMessage = "";
	try
	{
		treeNodePtr = reinterpret_cast<TreeNode *>(const_cast<void *>(lvTreeNodePtr));
		treeNodePtrOut = treeNodePtr->getMember();
		*lvTreeNodePtrOut = reinterpret_cast<void *>(treeNodePtrOut);
	}
	catch (MdsException *mdsE)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(mdsE->what());
	}
	catch (exception *e)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(e->what());
	}
	fillErrorCluster(errorCode, errorSource, errorMessage, error);
}

DLLEXPORT void mdsplus_treenode_getMembers(const void *lvTreeNodePtr, LPtrArrHdl lvPtrArrHdlOut, ErrorCluster *error)
{
	TreeNode *treeNodePtr = NULL;
	TreeNode **membersArrOut;
	int membersArrLen = 0;
	MgErr errorCode = noErr;
	const char *errorSource = __FUNCTION__;
	char *errorMessage = "";
	try
	{
		treeNodePtr = reinterpret_cast<TreeNode *>(const_cast<void *>(lvTreeNodePtr));
		membersArrOut = treeNodePtr->getMembers(&membersArrLen);
		// checks whether the size of a pointer is 32 bit or 64 bit depending upon the system architecture
		int32 typeCode = (sizeof(void *) > sizeof(int32)) ? iQ : iL;
		// resizes treenode array
		errorCode = NumericArrayResize(typeCode, 1, reinterpret_cast<UHandle *>(&lvPtrArrHdlOut), static_cast<int32>(membersArrLen));
		if (!errorCode)
		{
			for (int i = 0; i < membersArrLen; i++)
				(*lvPtrArrHdlOut)->elt[i] = static_cast<void *>(membersArrOut[i]);
			(*lvPtrArrHdlOut)->dimSize = static_cast<int32>(membersArrLen);
		}
		else
			errorMessage = "NumericArrayResize error";
		deleteNativeArray(reinterpret_cast<Data **>(membersArrOut));
	}
	catch (MdsException *mdsE)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(mdsE->what());
	}
	catch (exception *e)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(e->what());
	}
	fillErrorCluster(errorCode, errorSource, errorMessage, error);
}

DLLEXPORT void mdsplus_treenode_getMinPath(const void *lvTreeNodePtr, LStrHandle lvStrHdlOut, ErrorCluster *error)
{
	TreeNode *treeNodePtr = NULL;
	char *strOut = NULL;
	MgErr errorCode = noErr;
	const char *errorSource = __FUNCTION__;
	char *errorMessage = "";
	try
	{
		treeNodePtr = reinterpret_cast<TreeNode *>(const_cast<void *>(lvTreeNodePtr));
		strOut = treeNodePtr->getMinPath();
		int32 strOutLen = static_cast<int32>(strlen(strOut));
		errorCode = NumericArrayResize(uB, 1, reinterpret_cast<UHandle *>(&lvStrHdlOut), strOutLen);
		if (!errorCode)
		{
			MoveBlock(reinterpret_cast<uChar *>(strOut), LStrBuf(*lvStrHdlOut), strOutLen);
			(*lvStrHdlOut)->cnt = strOutLen;
		}
		else
			errorMessage = "NumericArrayResize error";
		deleteString(strOut);
	}
	catch (MdsException *mdsE)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(mdsE->what());
	}
	catch (exception *e)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(e->what());
	}
	fillErrorCluster(errorCode, errorSource, errorMessage, error);
}



DLLEXPORT void mdsplus_treenode_getNid(const void *lvTreeNodePtr, int *nidOut, ErrorCluster *error)
{
	TreeNode *treeNodePtr = NULL;
	MgErr errorCode = noErr;
	const char *errorSource = __FUNCTION__;
	char *errorMessage = "";
	try
	{
		treeNodePtr = reinterpret_cast<TreeNode *>(const_cast<void *>(lvTreeNodePtr));
		*nidOut = treeNodePtr->getNid();
	}
	catch (exception *e)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(e->what());
	}
	fillErrorCluster(errorCode, errorSource, errorMessage, error);
}

DLLEXPORT void mdsplus_treenode_getNode(const void *lvTreeNodePtr, void **lvTreeNodePtrOut, const char *relPathIn, ErrorCluster *error)
{
	TreeNode *treeNodePtr = NULL;
	TreeNode *treeNodePtrOut = NULL;
	MgErr errorCode = noErr;
	const char *errorSource = __FUNCTION__;
	char *errorMessage = "";
	try
	{
		treeNodePtr = reinterpret_cast<TreeNode *>(const_cast<void *>(lvTreeNodePtr));
		treeNodePtrOut = treeNodePtr->getNode(const_cast<char *>(relPathIn));
		*lvTreeNodePtrOut = reinterpret_cast<void *>(treeNodePtrOut);
	}
	catch (MdsException *mdsE)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(mdsE->what());
	}
	catch (exception *e)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(e->what());
	}
	fillErrorCluster(errorCode, errorSource, errorMessage, error);
}

DLLEXPORT void mdsplus_treenode_getNode_string(const void *lvTreeNodePtr, void **lvTreeNodePtrOut, const void *lvStringPtrIn, ErrorCluster *error)
{
	TreeNode *treeNodePtr = NULL;
	String *stringPtrIn = NULL;
	TreeNode *treeNodePtrOut = NULL;
	MgErr errorCode = noErr;
	const char *errorSource = __FUNCTION__;
	char *errorMessage = "";
	try
	{
		treeNodePtr = reinterpret_cast<TreeNode *>(const_cast<void *>(lvTreeNodePtr));
		stringPtrIn = reinterpret_cast<String *>(const_cast<void *>(lvStringPtrIn));
		treeNodePtrOut = treeNodePtr->getNode(stringPtrIn);
		*lvTreeNodePtrOut = reinterpret_cast<void *>(treeNodePtrOut);
	}
	catch (MdsException *mdsE)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(mdsE->what());
	}
	catch (exception *e)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(e->what());
	}
	fillErrorCluster(errorCode, errorSource, errorMessage, error);
}

DLLEXPORT void mdsplus_treenode_getNodeName(const void *lvTreeNodePtr, LStrHandle lvStrHdlOut, ErrorCluster *error)
{
	TreeNode *treeNodePtr = NULL;
	char *strOut = NULL;
	MgErr errorCode = noErr;
	const char *errorSource = __FUNCTION__;
	char *errorMessage = "";
	try
	{
		treeNodePtr = reinterpret_cast<TreeNode *>(const_cast<void *>(lvTreeNodePtr));
		strOut = treeNodePtr->getNodeName();
		int32 strOutLen = static_cast<int32>(strlen(strOut));
		errorCode = NumericArrayResize(uB, 1, reinterpret_cast<UHandle *>(&lvStrHdlOut), strOutLen);
		if (!errorCode)
		{
			MoveBlock(reinterpret_cast<uChar *>(strOut), LStrBuf(*lvStrHdlOut), strOutLen);
			(*lvStrHdlOut)->cnt = strOutLen;
		}
		else
			errorMessage = "NumericArrayResize error";
		deleteString(strOut);
	}
	catch (MdsException *mdsE)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(mdsE->what());
	}
	catch (exception *e)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(e->what());
	}
	fillErrorCluster(errorCode, errorSource, errorMessage, error);
}

DLLEXPORT void mdsplus_treenode_getNumChildren(const void *lvTreeNodePtr, int *numChildrenOut, ErrorCluster *error)
{
	TreeNode *treeNodePtr = NULL;
	MgErr errorCode = noErr;
	const char *errorSource = __FUNCTION__;
	char *errorMessage = "";
	try
	{
		treeNodePtr = reinterpret_cast<TreeNode *>(const_cast<void *>(lvTreeNodePtr));
		*numChildrenOut = treeNodePtr->getNumChildren();
	}
	catch (MdsException *mdsE)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(mdsE->what());
	}
	catch (exception *e)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(e->what());
	}
	fillErrorCluster(errorCode, errorSource, errorMessage, error);
}

DLLEXPORT void mdsplus_treenode_getNumDescendants(const void *lvTreeNodePtr, int *numDescendantsOut, ErrorCluster *error)
{
	TreeNode *treeNodePtr = NULL;
	MgErr errorCode = noErr;
	const char *errorSource = __FUNCTION__;
	char *errorMessage = "";
	try
	{
		treeNodePtr = reinterpret_cast<TreeNode *>(const_cast<void *>(lvTreeNodePtr));
		*numDescendantsOut = treeNodePtr->getNumDescendants();
	}
	catch (MdsException *mdsE)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(mdsE->what());
	}
	catch (exception *e)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(e->what());
	}
	fillErrorCluster(errorCode, errorSource, errorMessage, error);
}

DLLEXPORT void mdsplus_treenode_getNumElts(const void *lvTreeNodePtr, int *numEltsOut, ErrorCluster *error)
{
	TreeNode *treeNodePtr = NULL;
	MgErr errorCode = noErr;
	const char *errorSource = __FUNCTION__;
	char *errorMessage = "";
	try
	{
		treeNodePtr = reinterpret_cast<TreeNode *>(const_cast<void *>(lvTreeNodePtr));
		*numEltsOut = treeNodePtr->getNumElts();
	}
	catch (MdsException *mdsE)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(mdsE->what());
	}
	catch (exception *e)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(e->what());
	}
	fillErrorCluster(errorCode, errorSource, errorMessage, error);
}

DLLEXPORT void mdsplus_treenode_getNumMembers(const void *lvTreeNodePtr, int *numMembersOut, ErrorCluster *error)
{
	TreeNode *treeNodePtr = NULL;
	MgErr errorCode = noErr;
	const char *errorSource = __FUNCTION__;
	char *errorMessage = "";
	try
	{
		treeNodePtr = reinterpret_cast<TreeNode *>(const_cast<void *>(lvTreeNodePtr));
		*numMembersOut = treeNodePtr->getNumMembers();
	}
	catch (MdsException *mdsE)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(mdsE->what());
	}
	catch (exception *e)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(e->what());
	}
	fillErrorCluster(errorCode, errorSource, errorMessage, error);
}

DLLEXPORT void mdsplus_treenode_getNumSegments(const void *lvTreeNodePtr, int *numSegmentsOut, ErrorCluster *error)
{
	TreeNode *treeNodePtr = NULL;
	MgErr errorCode = noErr;
	const char *errorSource = __FUNCTION__;
	char *errorMessage = "";
	try
	{
		treeNodePtr = reinterpret_cast<TreeNode *>(const_cast<void *>(lvTreeNodePtr));
		*numSegmentsOut = treeNodePtr->getNumSegments();
	}
	catch (MdsException *mdsE)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(mdsE->what());
	}
	catch (exception *e)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(e->what());
	}
	fillErrorCluster(errorCode, errorSource, errorMessage, error);
}

DLLEXPORT void mdsplus_treenode_getOriginalPartName(const void *lvTreeNodePtr, LStrHandle lvStrHdlOut, ErrorCluster *error)
{
	TreeNode *treeNodePtr = NULL;
	char *strOut = NULL;
	MgErr errorCode = noErr;
	const char *errorSource = __FUNCTION__;
	char *errorMessage = "";
	try
	{
		treeNodePtr = reinterpret_cast<TreeNode *>(const_cast<void *>(lvTreeNodePtr));
		strOut = treeNodePtr->getOriginalPartName();
		int32 strOutLen = static_cast<int32>(strlen(strOut));
		errorCode = NumericArrayResize(uB, 1, reinterpret_cast<UHandle *>(&lvStrHdlOut), strOutLen);
		if (!errorCode)
		{
			MoveBlock(reinterpret_cast<uChar *>(strOut), LStrBuf(*lvStrHdlOut), strOutLen);
			(*lvStrHdlOut)->cnt = strOutLen;
		}
		else
			errorMessage = "NumericArrayResize error";
		deleteString(strOut);
	}
	catch (MdsException *mdsE)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(mdsE->what());
	}
	catch (exception *e)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(e->what());
	}
	fillErrorCluster(errorCode, errorSource, errorMessage, error);
}

DLLEXPORT void mdsplus_treenode_getOwnerId(const void *lvTreeNodePtr, int *ownerIdOut, ErrorCluster *error)
{
	TreeNode *treeNodePtr = NULL;
	MgErr errorCode = noErr;
	const char *errorSource = __FUNCTION__;
	char *errorMessage = "";
	try
	{
		treeNodePtr = reinterpret_cast<TreeNode *>(const_cast<void *>(lvTreeNodePtr));
		*ownerIdOut = treeNodePtr->getOwnerId();
	}
	catch (MdsException *mdsE)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(mdsE->what());
	}
	catch (exception *e)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(e->what());
	}
	fillErrorCluster(errorCode, errorSource, errorMessage, error);
}

DLLEXPORT void mdsplus_treenode_getParent(const void *lvTreeNodePtr, void **lvTreeNodePtrOut, ErrorCluster *error)
{
	TreeNode *treeNodePtr = NULL;
	TreeNode *treeNodePtrOut = NULL;
	MgErr errorCode = noErr;
	const char *errorSource = __FUNCTION__;
	char *errorMessage = "";
	try
	{
		treeNodePtr = reinterpret_cast<TreeNode *>(const_cast<void *>(lvTreeNodePtr));
		treeNodePtrOut = treeNodePtr->getParent();
		*lvTreeNodePtrOut = reinterpret_cast<void *>(treeNodePtrOut);
	}
	catch (MdsException *mdsE)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(mdsE->what());
	}
	catch (exception *e)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(e->what());
	}
	fillErrorCluster(errorCode, errorSource, errorMessage, error);
}

DLLEXPORT void mdsplus_treenode_getPath(const void *lvTreeNodePtr, LStrHandle lvStrHdlOut, ErrorCluster *error)
{
	TreeNode *treeNodePtr = NULL;
	char *strOut = NULL;
	MgErr errorCode = noErr;
	const char *errorSource = __FUNCTION__;
	char *errorMessage = "";
	try
	{
		treeNodePtr = reinterpret_cast<TreeNode *>(const_cast<void *>(lvTreeNodePtr));
		strOut = treeNodePtr->getPath();
		int32 strOutLen = static_cast<int32>(strlen(strOut));
		errorCode = NumericArrayResize(uB, 1, reinterpret_cast<UHandle *>(&lvStrHdlOut), strOutLen);
		if (!errorCode)
		{
			MoveBlock(reinterpret_cast<uChar *>(strOut), LStrBuf(*lvStrHdlOut), strOutLen);
			(*lvStrHdlOut)->cnt = strOutLen;
		}
		else
			errorMessage = "NumericArrayResize error";
		deleteString(strOut);
	}
	catch (MdsException *mdsE)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(mdsE->what());
	}
	catch (exception *e)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(e->what());
	}
	fillErrorCluster(errorCode, errorSource, errorMessage, error);
}
DLLEXPORT void mdsplus_treenode_getSegment(const void *lvTreeNodePtr, void **lvArrayPtrOut, int segIdxIn, ErrorCluster *error)
{
	TreeNode *treeNodePtr = NULL;
	Array *arrayPtrOut = NULL;
	MgErr errorCode = noErr;
	const char *errorSource = __FUNCTION__;
	char *errorMessage = "";
	try
	{
		treeNodePtr = reinterpret_cast<TreeNode *>(const_cast<void *>(lvTreeNodePtr));
		arrayPtrOut = treeNodePtr->getSegment(segIdxIn);
		*lvArrayPtrOut = reinterpret_cast<void *>(arrayPtrOut);
	}
	catch (MdsException *mdsE)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(mdsE->what());
	}
	catch (exception *e)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(e->what());
	}
	fillErrorCluster(errorCode, errorSource, errorMessage, error);
}

DLLEXPORT void mdsplus_treenode_getSegmentLimits(const void *lvTreeNodePtr, int segmentIdxIn, void **lvStartDataPtrOut, void **lvEndDataPtrOut, ErrorCluster *error)
{
	TreeNode *treeNodePtr = NULL;
	Data *startDataPtrOut = NULL;
	Data *endDataPtrOut = NULL;
	MgErr errorCode = noErr;
	const char *errorSource = __FUNCTION__;
	char *errorMessage = "";
	try
	{
		treeNodePtr = reinterpret_cast<TreeNode *>(const_cast<void *>(lvTreeNodePtr));
		treeNodePtr->getSegmentLimits(segmentIdxIn, &startDataPtrOut, &endDataPtrOut);
		*lvStartDataPtrOut = reinterpret_cast<void *>(startDataPtrOut);
		*lvEndDataPtrOut = reinterpret_cast<void *>(endDataPtrOut);
	}
	catch (MdsException *mdsE)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(mdsE->what());
	}
	catch (exception *e)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(e->what());
	}
	fillErrorCluster(errorCode, errorSource, errorMessage, error);
}

DLLEXPORT void mdsplus_treenode_getStatus(const void *lvTreeNodePtr, int *statusOut, ErrorCluster *error)
{
	TreeNode *treeNodePtr = NULL;
	MgErr errorCode = noErr;
	const char *errorSource = __FUNCTION__;
	char *errorMessage = "";
	try
	{
		treeNodePtr = reinterpret_cast<TreeNode *>(const_cast<void *>(lvTreeNodePtr));
		*statusOut = treeNodePtr->getStatus();
	}
	catch (MdsException *mdsE)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(mdsE->what());
	}
	catch (exception *e)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(e->what());
	}
	fillErrorCluster(errorCode, errorSource, errorMessage, error);
}

DLLEXPORT void mdsplus_treenode_getTimeInserted(const void *lvTreeNodePtr, _int64 *timeInsertedOut, ErrorCluster *error)
{
	TreeNode *treeNodePtr = NULL;
	MgErr errorCode = noErr;
	const char *errorSource = __FUNCTION__;
	char *errorMessage = "";
	try
	{
		treeNodePtr = reinterpret_cast<TreeNode *>(const_cast<void *>(lvTreeNodePtr));
		*timeInsertedOut = treeNodePtr->getTimeInserted();
	}
	catch (MdsException *mdsE)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(mdsE->what());
	}
	catch (exception *e)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(e->what());
	}
	fillErrorCluster(errorCode, errorSource, errorMessage, error);
}

DLLEXPORT void mdsplus_treenode_getTree(const void *lvTreeNodePtr, void **lvTreePtrOut, ErrorCluster *error)
{
	TreeNode *treeNodePtr = NULL;
	Tree *treePtrOut = NULL;
	MgErr errorCode = noErr;
	const char *errorSource = __FUNCTION__;
	char *errorMessage = "";
	try
	{
		treeNodePtr = reinterpret_cast<TreeNode *>(const_cast<void *>(lvTreeNodePtr));
		treePtrOut = treeNodePtr->getTree();
		*lvTreePtrOut = reinterpret_cast<void *>(treePtrOut);
	}
	catch (MdsException *mdsE)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(mdsE->what());
	}
	catch (exception *e)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(e->what());
	}
	fillErrorCluster(errorCode, errorSource, errorMessage, error);
}

DLLEXPORT void mdsplus_treenode_getUsage(const void *lvTreeNodePtr, LStrHandle lvStrHdlOut, ErrorCluster *error)
{
	TreeNode *treeNodePtr = NULL;
	char *strOut = NULL;
	MgErr errorCode = noErr;
	const char *errorSource = __FUNCTION__;
	char *errorMessage = "";
	try
	{
		treeNodePtr = reinterpret_cast<TreeNode *>(const_cast<void *>(lvTreeNodePtr));
		strOut = const_cast<char *>(treeNodePtr->getUsage());
		int32 strOutLen = static_cast<int32>(strlen(strOut));
		errorCode = NumericArrayResize(uB, 1, reinterpret_cast<UHandle *>(&lvStrHdlOut), strOutLen);
		if (!errorCode)
		{
			MoveBlock(reinterpret_cast<uChar *>(strOut), LStrBuf(*lvStrHdlOut), strOutLen);
			(*lvStrHdlOut)->cnt = strOutLen;
		}
		else
			errorMessage = "NumericArrayResize error";
		deleteString(strOut);
	}
	catch (MdsException *mdsE)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(mdsE->what());
	}
	catch (exception *e)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(e->what());
	}
	fillErrorCluster(errorCode, errorSource, errorMessage, error);
}
DLLEXPORT void mdsplus_treenode_isChild(const void *lvTreeNodePtr, LVBoolean *lvIsChildOut, ErrorCluster *error)
{
	TreeNode *treeNodePtr = NULL;
	MgErr errorCode = noErr;
	const char *errorSource = __FUNCTION__;
	char *errorMessage = "";
	try
	{
		treeNodePtr = reinterpret_cast<TreeNode *>(const_cast<void *>(lvTreeNodePtr));
		*lvIsChildOut = (treeNodePtr->isChild() == true) ? LVBooleanTrue : LVBooleanFalse;
	}
	catch (MdsException *mdsE)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(mdsE->what());
	}
	catch (exception *e)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(e->what());
	}
	fillErrorCluster(errorCode, errorSource, errorMessage, error);
}

DLLEXPORT void mdsplus_treenode_isCompressOnPut(const void *lvTreeNodePtr, LVBoolean *lvIsCompressOnPutOut, ErrorCluster *error)
{
	TreeNode *treeNodePtr = NULL;
	MgErr errorCode = noErr;
	const char *errorSource = __FUNCTION__;
	char *errorMessage = "";
	try
	{
		treeNodePtr = reinterpret_cast<TreeNode *>(const_cast<void *>(lvTreeNodePtr));
		*lvIsCompressOnPutOut = (treeNodePtr->isCompressOnPut() == true) ? LVBooleanTrue : LVBooleanFalse;
	}
	catch (MdsException *mdsE)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(mdsE->what());
	}
	catch (exception *e)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(e->what());
	}
	fillErrorCluster(errorCode, errorSource, errorMessage, error);
}

DLLEXPORT void mdsplus_treenode_isEssential(const void *lvTreeNodePtr, LVBoolean *lvIsEssentialOut, ErrorCluster *error)
{
	TreeNode *treeNodePtr = NULL;
	MgErr errorCode = noErr;
	const char *errorSource = __FUNCTION__;
	char *errorMessage = "";
	try
	{
		treeNodePtr = reinterpret_cast<TreeNode *>(const_cast<void *>(lvTreeNodePtr));
		*lvIsEssentialOut = (treeNodePtr->isEssential() == true) ? LVBooleanTrue : LVBooleanFalse;
	}
	catch (MdsException *mdsE)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(mdsE->what());
	}
	catch (exception *e)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(e->what());
	}
	fillErrorCluster(errorCode, errorSource, errorMessage, error);
}

DLLEXPORT void mdsplus_treenode_isIncludedInPulse(const void *lvTreeNodePtr, LVBoolean *lvIsIncludedInPulseOut, ErrorCluster *error)
{
	TreeNode *treeNodePtr = NULL;
	MgErr errorCode = noErr;
	const char *errorSource = __FUNCTION__;
	char *errorMessage = "";
	try
	{
		treeNodePtr = reinterpret_cast<TreeNode *>(const_cast<void *>(lvTreeNodePtr));
		*lvIsIncludedInPulseOut = (treeNodePtr->isIncludedInPulse() == true) ? LVBooleanTrue : LVBooleanFalse;
	}
	catch (MdsException *mdsE)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(mdsE->what());
	}
	catch (exception *e)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(e->what());
	}
	fillErrorCluster(errorCode, errorSource, errorMessage, error);
}

DLLEXPORT void mdsplus_treenode_isMember(const void *lvTreeNodePtr, LVBoolean *lvIsMemberOut, ErrorCluster *error)
{
	TreeNode *treeNodePtr = NULL;
	MgErr errorCode = noErr;
	const char *errorSource = __FUNCTION__;
	char *errorMessage = "";
	try
	{
		treeNodePtr = reinterpret_cast<TreeNode *>(const_cast<void *>(lvTreeNodePtr));
		*lvIsMemberOut = (treeNodePtr->isMember() == true) ? LVBooleanTrue : LVBooleanFalse;
	}
	catch (MdsException *mdsE)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(mdsE->what());
	}
	catch (exception *e)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(e->what());
	}
	fillErrorCluster(errorCode, errorSource, errorMessage, error);
}

DLLEXPORT void mdsplus_treenode_isNoWriteModel(const void *lvTreeNodePtr, LVBoolean *lvIsNoWriteModelOut, ErrorCluster *error)
{
	TreeNode *treeNodePtr = NULL;
	MgErr errorCode = noErr;
	const char *errorSource = __FUNCTION__;
	char *errorMessage = "";
	try
	{
		treeNodePtr = reinterpret_cast<TreeNode *>(const_cast<void *>(lvTreeNodePtr));
		*lvIsNoWriteModelOut = (treeNodePtr->isNoWriteModel() == true) ? LVBooleanTrue : LVBooleanFalse;
	}
	catch (MdsException *mdsE)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(mdsE->what());
	}
	catch (exception *e)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(e->what());
	}
	fillErrorCluster(errorCode, errorSource, errorMessage, error);
}

DLLEXPORT void mdsplus_treenode_isNoWriteShot(const void *lvTreeNodePtr, LVBoolean *lvIsNoWriteShotOut, ErrorCluster *error)
{
	TreeNode *treeNodePtr = NULL;
	MgErr errorCode = noErr;
	const char *errorSource = __FUNCTION__;
	char *errorMessage = "";
	try
	{
		treeNodePtr = reinterpret_cast<TreeNode *>(const_cast<void *>(lvTreeNodePtr));
		*lvIsNoWriteShotOut = (treeNodePtr->isNoWriteShot() == true) ? LVBooleanTrue : LVBooleanFalse;
	}
	catch (MdsException *mdsE)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(mdsE->what());
	}
	catch (exception *e)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(e->what());
	}
	fillErrorCluster(errorCode, errorSource, errorMessage, error);
}

DLLEXPORT void mdsplus_treenode_isOn(const void *lvTreeNodePtr, LVBoolean *lvIsOnOut, ErrorCluster *error)
{
	TreeNode *treeNodePtr = NULL;
	MgErr errorCode = noErr;
	const char *errorSource = __FUNCTION__;
	char *errorMessage = "";
	try
	{
		treeNodePtr = reinterpret_cast<TreeNode *>(const_cast<void *>(lvTreeNodePtr));
		*lvIsOnOut = (treeNodePtr->isOn() == true) ? LVBooleanTrue : LVBooleanFalse;
	}
	catch (MdsException *mdsE)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(mdsE->what());
	}
	catch (exception *e)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(e->what());
	}
	fillErrorCluster(errorCode, errorSource, errorMessage, error);
}

DLLEXPORT void mdsplus_treenode_isSetup(const void *lvTreeNodePtr, LVBoolean *lvIsSetupOut, ErrorCluster *error)
{
	TreeNode *treeNodePtr = NULL;
	MgErr errorCode = noErr;
	const char *errorSource = __FUNCTION__;
	char *errorMessage = "";
	try
	{
		treeNodePtr = reinterpret_cast<TreeNode *>(const_cast<void *>(lvTreeNodePtr));
		*lvIsSetupOut = (treeNodePtr->isSetup() == true) ? LVBooleanTrue : LVBooleanFalse;
	}
	catch (MdsException *mdsE)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(mdsE->what());
	}
	catch (exception *e)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(e->what());
	}
	fillErrorCluster(errorCode, errorSource, errorMessage, error);
}

DLLEXPORT void mdsplus_treenode_isWriteOnce(const void *lvTreeNodePtr, LVBoolean *lvIsWriteOnceOut, ErrorCluster *error)
{
	TreeNode *treeNodePtr = NULL;
	MgErr errorCode = noErr;
	const char *errorSource = __FUNCTION__;
	char *errorMessage = "";
	try
	{
		treeNodePtr = reinterpret_cast<TreeNode *>(const_cast<void *>(lvTreeNodePtr));
		*lvIsWriteOnceOut = (treeNodePtr->isWriteOnce() == true) ? LVBooleanTrue : LVBooleanFalse;
	}
	catch (MdsException *mdsE)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(mdsE->what());
	}
	catch (exception *e)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(e->what());
	}
	fillErrorCluster(errorCode, errorSource, errorMessage, error);
}

DLLEXPORT void mdsplus_treenode_makeSegment(const void *lvTreeNodePtr, const void *lvStartDataPtrIn, const void *lvEndDataPtrIn, const void *lvTimeDataPtrIn, const void *lvArrayPtrIn, ErrorCluster *error)
{
	TreeNode *treeNodePtr = NULL;
	Data *startDataPtrIn = NULL;
	Data *endDataPtrIn = NULL;
	Data *timeDataPtrIn = NULL;
	Array *initialDataArrayPtrIn = NULL;
	MgErr errorCode = noErr;
	const char *errorSource = __FUNCTION__;
	char *errorMessage = "";
	try
	{
		treeNodePtr = reinterpret_cast<TreeNode *>(const_cast<void *>(lvTreeNodePtr));
		startDataPtrIn = reinterpret_cast<Data *>(const_cast<void *>(lvStartDataPtrIn));
		endDataPtrIn = reinterpret_cast<Data *>(const_cast<void *>(lvEndDataPtrIn));
		timeDataPtrIn = reinterpret_cast<Data *>(const_cast<void *>(lvTimeDataPtrIn));
		initialDataArrayPtrIn = reinterpret_cast<Array *>(const_cast<void *>(lvArrayPtrIn));
		treeNodePtr->makeSegment(startDataPtrIn, endDataPtrIn, timeDataPtrIn, initialDataArrayPtrIn);
	}
	catch (MdsException *mdsE)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(mdsE->what());
	}
	catch (exception *e)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(e->what());
	}
	fillErrorCluster(errorCode, errorSource, errorMessage, error);
}

DLLEXPORT void mdsplus_treenode_makeTimestampedSegment(const void *lvTreeNodePtr, const void *lvArrayPtrIn, const LLngArrHdl lvLngArrHdlIn, ErrorCluster *error)
{
	TreeNode *treeNodePtr = NULL;
	Array *arrayPtrIn = NULL;
	_int64 *timesArrIn = NULL;	
	MgErr errorCode = noErr;
	const char *errorSource = __FUNCTION__;
	char *errorMessage = "";
	try
	{
		treeNodePtr = reinterpret_cast<TreeNode *>(const_cast<void *>(lvTreeNodePtr));
		arrayPtrIn = reinterpret_cast<Array *>(const_cast<void *>(lvArrayPtrIn));
		int timesArrLen = static_cast<int>((*lvLngArrHdlIn)->dimSize);
		timesArrIn = new _int64[timesArrLen];
		for (int i = 0; i < timesArrLen; i++)
			timesArrIn[i] = static_cast<_int64>((*lvLngArrHdlIn)->elt[i]);
		treeNodePtr->makeTimestampedSegment(arrayPtrIn, timesArrIn);
		delete[] timesArrIn;
	}
	catch (MdsException *mdsE)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(mdsE->what());
	}
	catch (exception *e)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(e->what());
	}
	fillErrorCluster(errorCode, errorSource, errorMessage, error);
}

DLLEXPORT void mdsplus_treenode_move(const void *lvTreeNodePtr, const void *lvTreeNodePtrIn, ErrorCluster *error)
{
	TreeNode *treeNodePtr = NULL;
	TreeNode *treeNodeParentPtr = NULL;
	MgErr errorCode = noErr;
	const char *errorSource = __FUNCTION__;
	char *errorMessage = "";
	try
	{
		treeNodePtr = reinterpret_cast<TreeNode *>(const_cast<void *>(lvTreeNodePtr));
		treeNodeParentPtr = reinterpret_cast<TreeNode *>(const_cast<void *>(lvTreeNodePtrIn));
		treeNodePtr->move(treeNodeParentPtr);
	}
	catch (MdsException *mdsE)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(mdsE->what());
	}
	catch (exception *e)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(e->what());
	}
	fillErrorCluster(errorCode, errorSource, errorMessage, error);
}

DLLEXPORT void mdsplus_treenode_move_newName(const void *lvTreeNodePtr, const void *lvTreeNodePtrIn, const char *newNameIn, ErrorCluster *error)
{
	TreeNode *treeNodePtr = NULL;
	TreeNode *treeNodeParentPtr = NULL;
	MgErr errorCode = noErr;
	const char *errorSource = __FUNCTION__;
	char *errorMessage = "";
	try
	{
		treeNodePtr = reinterpret_cast<TreeNode *>(const_cast<void *>(lvTreeNodePtr));
		treeNodeParentPtr = reinterpret_cast<TreeNode *>(const_cast<void *>(lvTreeNodePtrIn));
		treeNodePtr->move(treeNodeParentPtr, const_cast<char *>(newNameIn));
	}
	catch (MdsException *mdsE)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(mdsE->what());
	}
	catch (exception *e)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(e->what());
	}
	fillErrorCluster(errorCode, errorSource, errorMessage, error);
}

DLLEXPORT void mdsplus_treenode_putData(const void *lvTreeNodePtr, const void *lvDataPtrIn, ErrorCluster *error)
{
	TreeNode *treeNodePtr = NULL;
	Data *dataPtrIn = NULL;
	MgErr errorCode = noErr;
	const char *errorSource = __FUNCTION__;
	char *errorMessage = "";
	try
	{
		treeNodePtr = reinterpret_cast<TreeNode *>(const_cast<void *>(lvTreeNodePtr));
		dataPtrIn = reinterpret_cast<Data *>(const_cast<void *>(lvDataPtrIn));
		treeNodePtr->putData(dataPtrIn);
	}
	catch (MdsException *mdsE)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(mdsE->what());
	}
	catch (exception *e)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(e->what());
	}
	fillErrorCluster(errorCode, errorSource, errorMessage, error);
}


DLLEXPORT void mdsplus_treenode_putRow(const void *lvTreeNodePtr, const void *lvDataPtrIn, _int64 *timeIn, int sizeIn, ErrorCluster *error)
{
	TreeNode *treeNodePtr = NULL;
	Data *dataPtrIn = NULL;
	MgErr errorCode = noErr;
	const char *errorSource = __FUNCTION__;
	char *errorMessage = "";
	try
	{
		treeNodePtr = reinterpret_cast<TreeNode *>(const_cast<void *>(lvTreeNodePtr));
		dataPtrIn = reinterpret_cast<Data *>(const_cast<void *>(lvDataPtrIn));
		treeNodePtr->putRow(dataPtrIn, timeIn, sizeIn);
	}
	catch (MdsException *mdsE)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(mdsE->what());
	}
	catch (exception *e)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(e->what());
	}
	fillErrorCluster(errorCode, errorSource, errorMessage, error);
}

DLLEXPORT void mdsplus_treenode_putSegment(const void *lvTreeNodePtr, const void *lvArrayPtrIn, int ofsIn, ErrorCluster *error)
{
	TreeNode *treeNodePtr = NULL;
	Array *arrayPtrIn = NULL;
	MgErr errorCode = noErr;
	const char *errorSource = __FUNCTION__;
	char *errorMessage = "";
	try
	{
		treeNodePtr = reinterpret_cast<TreeNode *>(const_cast<void *>(lvTreeNodePtr));
		arrayPtrIn = reinterpret_cast<Array *>(const_cast<void *>(lvArrayPtrIn));
		treeNodePtr->putSegment(arrayPtrIn, ofsIn);
	}
	catch (MdsException *mdsE)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(mdsE->what());
	}
	catch (exception *e)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(e->what());
	}
	fillErrorCluster(errorCode, errorSource, errorMessage, error);
}

DLLEXPORT void mdsplus_treenode_putTimestampedSegment(const void *lvTreeNodePtr, const void *lvArrayPtrIn, const LLngArrHdl lvLngArrHdlIn ,ErrorCluster *error)
{
	TreeNode *treeNodePtr = NULL;
	Array *arrayPtrIn = NULL;
	_int64 *timesArrIn = NULL;	
	MgErr errorCode = noErr;
	const char *errorSource = __FUNCTION__;
	char *errorMessage = "";
	try
	{
		treeNodePtr = reinterpret_cast<TreeNode *>(const_cast<void *>(lvTreeNodePtr));
		arrayPtrIn = reinterpret_cast<Array *>(const_cast<void *>(lvArrayPtrIn));
		int timesArrLen = static_cast<int>((*lvLngArrHdlIn)->dimSize);
		timesArrIn = new _int64[timesArrLen];
		for (int i = 0; i < timesArrLen; i++)
			timesArrIn[i] = static_cast<_int64>((*lvLngArrHdlIn)->elt[i]);
		treeNodePtr->putTimestampedSegment(arrayPtrIn, timesArrIn);
		delete[] timesArrIn;
	}
	catch (MdsException *mdsE)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(mdsE->what());
	}
	catch (exception *e)
	{
		delete[] timesArrIn;
		errorCode = bogusError;
		errorMessage = const_cast<char *>(e->what());
	}
	fillErrorCluster(errorCode, errorSource, errorMessage, error);
}

DLLEXPORT void mdsplus_treenode_remove(const void *lvTreeNodePtr, const char *nameIn, ErrorCluster *error)
{
	TreeNode *treeNodePtr = NULL;
	MgErr errorCode = noErr;
	const char *errorSource = __FUNCTION__;
	char *errorMessage = "";
	try
	{
		treeNodePtr = reinterpret_cast<TreeNode *>(const_cast<void *>(lvTreeNodePtr));
		treeNodePtr->remove(const_cast<char *>(nameIn));
	}
	catch (MdsException *mdsE)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(mdsE->what());
	}
	catch (exception *e)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(e->what());
	}
	fillErrorCluster(errorCode, errorSource, errorMessage, error);
}

DLLEXPORT void mdsplus_treenode_removeTag(const void *lvTreeNodePtr, const char *tagNameIn, ErrorCluster *error)
{
	TreeNode *treeNodePtr = NULL;
	MgErr errorCode = noErr;
	const char *errorSource = __FUNCTION__;
	char *errorMessage = "";
	try
	{
		treeNodePtr = reinterpret_cast<TreeNode *>(const_cast<void *>(lvTreeNodePtr));
		treeNodePtr->removeTag(const_cast<char *>(tagNameIn));
	}
	catch (MdsException *mdsE)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(mdsE->what());
	}
	catch (exception *e)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(e->what());
	}
	fillErrorCluster(errorCode, errorSource, errorMessage, error);
}

DLLEXPORT void mdsplus_treenode_rename(const void *lvTreeNodePtr, const char *newNameIn, ErrorCluster *error)
{
	TreeNode *treeNodePtr = NULL;
	MgErr errorCode = noErr;
	const char *errorSource = __FUNCTION__;
	char *errorMessage = "";
	try
	{
		treeNodePtr = reinterpret_cast<TreeNode *>(const_cast<void *>(lvTreeNodePtr));
		treeNodePtr->rename(const_cast<char *>(newNameIn));
	}
	catch (MdsException *mdsE)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(mdsE->what());
	}
	catch (exception *e)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(e->what());
	}
	fillErrorCluster(errorCode, errorSource, errorMessage, error);
}

DLLEXPORT void mdsplus_treenode_setCompressOnPut(const void *lvTreeNodePtr, LVBoolean *lvCompressOnPutIn, ErrorCluster *error)
{
	TreeNode *treeNodePtr = NULL;
	MgErr errorCode = noErr;
	const char *errorSource = __FUNCTION__;
	char *errorMessage = "";
	try
	{
		treeNodePtr = reinterpret_cast<TreeNode *>(const_cast<void *>(lvTreeNodePtr));
		if (*lvCompressOnPutIn == LVBooleanTrue)
			treeNodePtr->setCompressOnPut(true);
		else
			treeNodePtr->setCompressOnPut(false);
	}
	catch (MdsException *mdsE)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(mdsE->what());
	}
	catch (exception *e)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(e->what());
	}
	fillErrorCluster(errorCode, errorSource, errorMessage, error);
}

DLLEXPORT void mdsplus_treenode_setEssential(const void *lvTreeNodePtr, LVBoolean *lvEssentialIn, ErrorCluster *error)
{
	TreeNode *treeNodePtr = NULL;
	MgErr errorCode = noErr;
	const char *errorSource = __FUNCTION__;
	char *errorMessage = "";
	try
	{
		treeNodePtr = reinterpret_cast<TreeNode *>(const_cast<void *>(lvTreeNodePtr));
		if (*lvEssentialIn == LVBooleanTrue)
			treeNodePtr->setEssential(true);
		else
			treeNodePtr->setEssential(false);
	}
	catch (MdsException *mdsE)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(mdsE->what());
	}
	catch (exception *e)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(e->what());
	}
	fillErrorCluster(errorCode, errorSource, errorMessage, error);
}

DLLEXPORT void mdsplus_treenode_setIncludedInPulse(const void *lvTreeNodePtr, LVBoolean *lvIncludedInPulseIn, ErrorCluster *error)
{
	TreeNode *treeNodePtr = NULL;
	MgErr errorCode = noErr;
	const char *errorSource = __FUNCTION__;
	char *errorMessage = "";
	try
	{
		treeNodePtr = reinterpret_cast<TreeNode *>(const_cast<void *>(lvTreeNodePtr));
		if (*lvIncludedInPulseIn == LVBooleanTrue)
			treeNodePtr->setIncludedInPulse(true);
		else
			treeNodePtr->setIncludedInPulse(false);
	}
	catch (MdsException *mdsE)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(mdsE->what());
	}
	catch (exception *e)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(e->what());
	}
	fillErrorCluster(errorCode, errorSource, errorMessage, error);
}

DLLEXPORT void mdsplus_treenode_setNoWriteModel(const void *lvTreeNodePtr, LVBoolean *lvSetNoWriteModelIn, ErrorCluster *error)
{
	TreeNode *treeNodePtr = NULL;
	MgErr errorCode = noErr;
	const char *errorSource = __FUNCTION__;
	char *errorMessage = "";
	try
	{
		treeNodePtr = reinterpret_cast<TreeNode *>(const_cast<void *>(lvTreeNodePtr));
		if (*lvSetNoWriteModelIn == LVBooleanTrue)
			treeNodePtr->setNoWriteModel(true);
		else
			treeNodePtr->setNoWriteModel(false);
	}
	catch (MdsException *mdsE)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(mdsE->what());
	}
	catch (exception *e)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(e->what());
	}
	fillErrorCluster(errorCode, errorSource, errorMessage, error);
}

DLLEXPORT void mdsplus_treenode_setNoWriteShot(const void *lvTreeNodePtr, LVBoolean *lvNoWriteShotIn, ErrorCluster *error)
{
	TreeNode *treeNodePtr = NULL;
	MgErr errorCode = noErr;
	const char *errorSource = __FUNCTION__;
	char *errorMessage = "";
	try
	{
		treeNodePtr = reinterpret_cast<TreeNode *>(const_cast<void *>(lvTreeNodePtr));
		if (*lvNoWriteShotIn == LVBooleanTrue)
			treeNodePtr->setNoWriteShot(true);
		else
			treeNodePtr->setNoWriteShot(false);
	}
	catch (MdsException *mdsE)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(mdsE->what());
	}
	catch (exception *e)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(e->what());
	}
	fillErrorCluster(errorCode, errorSource, errorMessage, error);
}

DLLEXPORT void mdsplus_treenode_setOn(const void *lvTreeNodePtr, LVBoolean *lvOnIn, ErrorCluster *error)
{
	TreeNode *treeNodePtr = NULL;
	MgErr errorCode = noErr;
	const char *errorSource = __FUNCTION__;
	char *errorMessage = "";
	try
	{
		treeNodePtr = reinterpret_cast<TreeNode *>(const_cast<void *>(lvTreeNodePtr));
		if (*lvOnIn == LVBooleanTrue)
			treeNodePtr->setOn(true);
		else
			treeNodePtr->setOn(false);
	}
	catch (MdsException *mdsE)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(mdsE->what());
	}
	catch (exception *e)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(e->what());
	}
	fillErrorCluster(errorCode, errorSource, errorMessage, error);
}

DLLEXPORT void mdsplus_treenode_setSubTree(const void *lvTreeNodePtr, LVBoolean *lvSubTreeIn, ErrorCluster *error)
{
	TreeNode *treeNodePtr = NULL;
	MgErr errorCode = noErr;
	const char *errorSource = __FUNCTION__;
	char *errorMessage = "";
	try
	{
		treeNodePtr = reinterpret_cast<TreeNode *>(const_cast<void *>(lvTreeNodePtr));
		if (*lvSubTreeIn == LVBooleanTrue)
			treeNodePtr->setSubtree(true);
		else
			treeNodePtr->setSubtree(false);
	}
	catch (MdsException *mdsE)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(mdsE->what());
	}
	catch (exception *e)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(e->what());
	}
	fillErrorCluster(errorCode, errorSource, errorMessage, error);
}

DLLEXPORT void mdsplus_treenode_setTree(const void *lvTreeNodePtr, const void *lvTreePtrIn, ErrorCluster *error)
{
	TreeNode *treeNodePtr = NULL;
	Tree *treePtrIn = NULL;
	MgErr errorCode = noErr;
	const char *errorSource = __FUNCTION__;
	char *errorMessage = "";
	try
	{
		treeNodePtr = reinterpret_cast<TreeNode *>(const_cast<void *>(lvTreeNodePtr));
		treePtrIn = reinterpret_cast<Tree *>(const_cast<void *>(lvTreePtrIn));
		treeNodePtr->setTree(treePtrIn);
	}
	catch (exception *e)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(e->what());
	}
	fillErrorCluster(errorCode, errorSource, errorMessage, error);
}

DLLEXPORT void mdsplus_treenode_setWriteOnce(const void *lvTreeNodePtr, LVBoolean *lvWriteOnceIn, ErrorCluster *error)
{
	TreeNode *treeNodePtr = NULL;
	MgErr errorCode = noErr;
	const char *errorSource = __FUNCTION__;
	char *errorMessage = "";
	try
	{
		treeNodePtr = reinterpret_cast<TreeNode *>(const_cast<void *>(lvTreeNodePtr));
		if (*lvWriteOnceIn == LVBooleanTrue)
			treeNodePtr->setWriteOnce(true);
		else
			treeNodePtr->setWriteOnce(false);
	}
	catch (MdsException *mdsE)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(mdsE->what());
	}
	catch (exception *e)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(e->what());
	}
	fillErrorCluster(errorCode, errorSource, errorMessage, error);
}

DLLEXPORT void mdsplus_treenode_updateSegment(const void *lvTreeNodePtr, const void *lvStartDataPtrIn, const void *lvEndDataPtrIn, const void *lvTimeDataPtrIn, ErrorCluster *error)
{
	TreeNode *treeNodePtr = NULL;
	Data *startDataPtrIn = NULL;
	Data *endDataPtrIn = NULL;
	Data *timeDataPtrIn = NULL;
	MgErr errorCode = noErr;
	const char *errorSource = __FUNCTION__;
	char *errorMessage = "";
	try
	{
		treeNodePtr = reinterpret_cast<TreeNode *>(const_cast<void *>(lvTreeNodePtr));
		startDataPtrIn = reinterpret_cast<Data *>(const_cast<void *>(lvStartDataPtrIn));
		endDataPtrIn = reinterpret_cast<Data *>(const_cast<void *>(lvEndDataPtrIn));
		timeDataPtrIn = reinterpret_cast<Data *>(const_cast<void *>(lvTimeDataPtrIn));
		treeNodePtr->updateSegment(startDataPtrIn, endDataPtrIn, timeDataPtrIn);
	}
	catch (MdsException *mdsE)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(mdsE->what());
	}
	catch (exception *e)
	{
		errorCode = bogusError;
		errorMessage = const_cast<char *>(e->what());
	}
	fillErrorCluster(errorCode, errorSource, errorMessage, error);
}

/********************************************************************************************************
												TREENODEARRAY
 ********************************************************************************************************/

DLLEXPORT void mdsplus_treenodearray_destructor(void **lvTreeNodeArrayPtr)
{
	TreeNodeArray *treeNodeArrayPtr = reinterpret_cast<TreeNodeArray *>(*lvTreeNodeArrayPtr);
	delete treeNodeArrayPtr;
	*lvTreeNodeArrayPtr = NULL;
}

/********************************************************************************************************
												TREEPATH
 ********************************************************************************************************/

DLLEXPORT void mdsplus_treepath_destructor(void **lvTreePathPtr)
{
	TreePath *treePathPtr = reinterpret_cast<TreePath *>(*lvTreePathPtr);
	deleteData(treePathPtr);
	*lvTreePathPtr = NULL;
}
