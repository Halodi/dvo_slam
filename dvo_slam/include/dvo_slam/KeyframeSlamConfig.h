#ifndef KEYFRAME_SLAM_CONFIG_H
#define KEYFRAME_SLAM_CONFIG_H

namespace dvo_slam
{
    struct KeyframeSlamConfig
    {
        double max_translational_distance, max_rotational_distance, min_entropy_ratio, min_eq_sys_constraint_ratio,
               constraint_search_radius, constraint_min_entropy_ratio_coarse, constraint_min_entropy_ratio_fine, constraint_min_eq_sys_constraint_ratio;
        bool graph_opt_robust;
        size_t graph_opt_iterations;
        bool graph_opt_dense_graph, graph_opt_remove_outliers;
        double graph_opt_outlier_weight_threshold;
        size_t graph_opt_min_distance;
        bool graph_opt_final;
        size_t graph_opt_final_iterations;
        bool graph_opt_final_dense_graph, graph_opt_final_remove_outliers;
        double graph_opt_final_outlier_weight_threshold;
        bool use_multithreading;
    };
};

#endif
