#pragma once
#include "core/graph/model.h"

namespace onnxruntime {
namespace training {
namespace api {

// static std::unique_ptr<Environment> env;
const std::vector<std::string> GRAD_SUFFIX{"_grad.accumulation.buffer", "_grad"};
const std::string MOMENT_1{".exp_avg"};
const std::string MOMENT_2{".exp_avg_sq"};

void GetGraphInputOutputNames(const Graph& graph,
                              std::vector<std::string>& input_names,
                              std::vector<std::string>& output_names);
bool GetParamNameFromSuffix(const std::string& name, const std::string& suffix, std::string& param_name);

bool GetParamNameFromGradient(const std::string& grad_name, std::string& param_name);

Status OrtValueLike(const SessionState& sess_state, const OrtValue& input_val, OrtValue& output_val);

}  // namespace api
}  // namespace training
}  // namespace onnxruntime
