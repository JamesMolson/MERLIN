#include "AcceleratorModel/Frames/ComponentFrame.h"
#include "BeamDynamics/ProcessStepManager.h"
#include "BeamModel/Bunch.h"
#include "RingDynamics/DoTrack.h"

namespace RingDynamicsImpl {
	
	DoTrack::DoTrack(ProcessStepManager& aPSM, Bunch& aBunch)
		: itsPSM(aPSM), itsBunch(aBunch) {}
	
	void DoTrack::operator ()(ComponentFrame* frame)
	{
		Transform3D t_in = frame->GetEntrancePlaneTransform();
		itsBunch.ApplyTransformation(t_in);
		
		itsPSM.Track(frame->GetComponent());
		
		Transform3D t_out = frame->GetExitPlaneTransform();
		itsBunch.ApplyTransformation(t_out);
	}
	
};