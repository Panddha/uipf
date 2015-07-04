#ifndef MODULEMANAGER_H
#define MODULEMANAGER_H

#include <opencv2/opencv.hpp>
#include "Configuration.hpp"
#include "ModuleInterface.hpp"
#include "MetaData.hpp"
#include <QObjectList>
#include <QPluginLoader>
#include <map>

namespace uipf{

class ModuleManager{

	public:
		// constructor
		ModuleManager();
		// destructor
		~ModuleManager(void);

		// runs the module chain with the params
		void run(Configuration);

		// returns meta data information for a named module
		MetaData getModuleMetaData(const std::string& name);

		// returns a value indicating whether the named module exists
		bool hasModule(const std::string& name);

		// returns a map of module name => meta data
		std::map<std::string, MetaData> getAllModuleMetaData();

		//if set modules should finish their work
		void requestStop(){context_.bStopRequested_=true;}

		//tell modules that we have a GUI
		void setHaveGUI(){context_.bHaveGUI_=true;}

	private:
		// module chain

		ModuleInterface* loadModule(const std::string& name);

		void initModules();

		// map: module name -> plugin loader instance which can instantiate a module
		std::map<std::string, QPluginLoader*> plugins_;

		Context context_;
};

}

#endif

