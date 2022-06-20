#include "animal.h"
class cat : public animal {
	public:
		cat();
		~cat();
		void run() override;
};
