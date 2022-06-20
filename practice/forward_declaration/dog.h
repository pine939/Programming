#include "animal.h"
class dog : public animal {
	public:
		dog();
		~dog();
		void run() override;
};
