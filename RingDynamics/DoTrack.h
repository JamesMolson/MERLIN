class Bunch;
class ProcessStepManager;
class ComponentFrame;

namespace RingDynamicsImpl {
	
	class DoTrack
	{
	private:
		ProcessStepManager& itsPSM;
		Bunch& itsBunch;
		
	public:
		DoTrack(ProcessStepManager& aPSM, Bunch& bunch0);
		void operator()(ComponentFrame* frame);
	};
	
};
