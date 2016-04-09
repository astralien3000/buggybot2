#include <chain_from_ik_export.hpp>
#include <ik_export.hpp>

using lf = ik_export::objects::armature::bones::forearm_left_front::endpoint;
using rf = ik_export::objects::armature::bones::forearm_right_front::endpoint;
using lb = ik_export::objects::armature::bones::forearm_left_back::endpoint;
using rb = ik_export::objects::armature::bones::forearm_right_back::endpoint;

using LFChain = ChainFromIKExport<lf>::ChainBuilder::Chain;
using RFChain = ChainFromIKExport<rf>::ChainBuilder::Chain;
using LBChain = ChainFromIKExport<lb>::ChainBuilder::Chain;
using RBChain = ChainFromIKExport<rb>::ChainBuilder::Chain;
