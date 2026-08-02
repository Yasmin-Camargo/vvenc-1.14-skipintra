
/*
This inline function was automatically generated using DecisionTreeToCpp Converter

It takes feature vector as single argument:
feature_vector[0] - FrameLevel
feature_vector[1] - SplitSeries
feature_vector[2] - inter_had_per_pixel
feature_vector[3] - ref_line_range
feature_vector[4] - num_intra_ciip_neighbors
feature_vector[5] - left_depth
feature_vector[6] - relative_block_area
feature_vector[7] - delta_qp
feature_vector[8] - contrast_ratio
feature_vector[9] - directional_dominance
feature_vector[10] - var_mismatch
feature_vector[11] - blk_std_v
feature_vector[12] - blk_range


It returns index of predicted class:
0 - 0
1 - 1


Simply include this file to your project and use it
*/

#include <vector>

inline int decision_tree_single_mdecision_tree_All_Blocks_intrakept(const std::vector<double> & feature_vector) 
{
	if (feature_vector.at(4) <= 0.5) {
		if (feature_vector.at(2) <= -0.01) {
			return 1;
		}
		else {
			if (feature_vector.at(6) <= 0.0) {
				if (feature_vector.at(7) <= 4.5) {
					if (feature_vector.at(2) <= 10.42) {
						if (feature_vector.at(11) <= 5.79) {
							if (feature_vector.at(2) <= 3.88) {
								if (feature_vector.at(11) <= 2.48) {
									if (feature_vector.at(7) <= -0.5) {
										return 0;
									}
									else {
										if (feature_vector.at(6) <= 0.0) {
											return 0;
										}
										else {
											if (feature_vector.at(12) <= 14.5) {
												return 1;
											}
											else {
												return 0;
											}
										}
									}
								}
								else {
									if (feature_vector.at(7) <= 0.5) {
										return 0;
									}
									else {
										if (feature_vector.at(8) <= 0.16) {
											return 0;
										}
										else {
											return 0;
										}
									}
								}
							}
							else {
								if (feature_vector.at(2) <= 6.23) {
									if (feature_vector.at(11) <= 2.95) {
										if (feature_vector.at(8) <= 0.71) {
											return 1;
										}
										else {
											return 0;
										}
									}
									else {
										if (feature_vector.at(2) <= 4.77) {
											return 0;
										}
										else {
											if (feature_vector.at(8) <= 0.38) {
												return 0;
											}
											else {
												return 0;
											}
										}
									}
								}
								else {
									if (feature_vector.at(11) <= 4.9) {
										return 1;
									}
									else {
										return 0;
									}
								}
							}
						}
						else {
							if (feature_vector.at(2) <= 5.87) {
								if (feature_vector.at(9) <= 0.87) {
									if (feature_vector.at(8) <= 0.22) {
										return 0;
									}
									else {
										if (feature_vector.at(7) <= 0.5) {
											return 0;
										}
										else {
											return 0;
										}
									}
								}
								else {
									if (feature_vector.at(8) <= 0.61) {
										if (feature_vector.at(2) <= 3.32) {
											return 0;
										}
										else {
											return 0;
										}
									}
									else {
										return 0;
									}
								}
							}
							else {
								if (feature_vector.at(12) <= 54.5) {
									if (feature_vector.at(6) <= 0.0) {
										if (feature_vector.at(2) <= 8.07) {
											return 0;
										}
										else {
											return 1;
										}
									}
									else {
										if (feature_vector.at(9) <= 0.51) {
											return 0;
										}
										else {
											return 1;
										}
									}
								}
								else {
									if (feature_vector.at(8) <= 0.62) {
										if (feature_vector.at(9) <= 0.77) {
											return 0;
										}
										else {
											return 1;
										}
									}
									else {
										if (feature_vector.at(1) <= 19505.0) {
											if (feature_vector.at(6) <= 0.0) {
												return 0;
											}
											else {
												return 0;
											}
										}
										else {
											if (feature_vector.at(6) <= 0.0) {
												return 0;
											}
											else {
												return 0;
											}
										}
									}
								}
							}
						}
					}
					else {
						if (feature_vector.at(11) <= 9.94) {
							if (feature_vector.at(11) <= 6.96) {
								return 1;
							}
							else {
								if (feature_vector.at(2) <= 16.14) {
									if (feature_vector.at(6) <= 0.0) {
										return 1;
									}
									else {
										return 0;
									}
								}
								else {
									return 1;
								}
							}
						}
						else {
							if (feature_vector.at(6) <= 0.0) {
								if (feature_vector.at(12) <= 90.5) {
									return 1;
								}
								else {
									if (feature_vector.at(2) <= 16.25) {
										return 0;
									}
									else {
										return 1;
									}
								}
							}
							else {
								if (feature_vector.at(2) <= 17.98) {
									if (feature_vector.at(12) <= 89.5) {
										if (feature_vector.at(2) <= 14.14) {
											return 0;
										}
										else {
											return 0;
										}
									}
									else {
										return 0;
									}
								}
								else {
									if (feature_vector.at(12) <= 121.5) {
										if (feature_vector.at(1) <= 50209.0) {
											return 0;
										}
										else {
											return 1;
										}
									}
									else {
										if (feature_vector.at(1) <= 1148449.0) {
											if (feature_vector.at(2) <= 28.03) {
												return 0;
											}
											else {
												return 0;
											}
										}
										else {
											return 1;
										}
									}
								}
							}
						}
					}
				}
				else {
					if (feature_vector.at(6) <= 0.0) {
						if (feature_vector.at(12) <= 120.5) {
							if (feature_vector.at(2) <= 9.47) {
								if (feature_vector.at(11) <= 5.26) {
									if (feature_vector.at(2) <= 6.41) {
										if (feature_vector.at(11) <= 3.36) {
											if (feature_vector.at(2) <= 4.25) {
												return 0;
											}
											else {
												return 1;
											}
										}
										else {
											if (feature_vector.at(2) <= 4.16) {
												return 0;
											}
											else {
												return 0;
											}
										}
									}
									else {
										if (feature_vector.at(11) <= 3.63) {
											return 1;
										}
										else {
											return 1;
										}
									}
								}
								else {
									if (feature_vector.at(9) <= 0.89) {
										if (feature_vector.at(7) <= 7.5) {
											if (feature_vector.at(2) <= 6.61) {
												return 0;
											}
											else {
												return 0;
											}
										}
										else {
											if (feature_vector.at(1) <= 19505.0) {
												return 0;
											}
											else {
												return 0;
											}
										}
									}
									else {
										if (feature_vector.at(8) <= 0.93) {
											return 1;
										}
										else {
											return 0;
										}
									}
								}
							}
							else {
								if (feature_vector.at(11) <= 10.55) {
									if (feature_vector.at(2) <= 13.16) {
										if (feature_vector.at(12) <= 55.5) {
											return 1;
										}
										else {
											return 1;
										}
									}
									else {
										return 1;
									}
								}
								else {
									if (feature_vector.at(2) <= 15.52) {
										if (feature_vector.at(12) <= 81.5) {
											if (feature_vector.at(12) <= 59.5) {
												return 1;
											}
											else {
												return 0;
											}
										}
										else {
											if (feature_vector.at(1) <= 5169.0) {
												return 0;
											}
											else {
												return 0;
											}
										}
									}
									else {
										if (feature_vector.at(12) <= 88.5) {
											return 1;
										}
										else {
											if (feature_vector.at(2) <= 22.03) {
												return 0;
											}
											else {
												return 1;
											}
										}
									}
								}
							}
						}
						else {
							if (feature_vector.at(2) <= 26.17) {
								if (feature_vector.at(9) <= 0.82) {
									if (feature_vector.at(1) <= 5169.0) {
										if (feature_vector.at(2) <= 10.26) {
											return 0;
										}
										else {
											return 0;
										}
									}
									else {
										if (feature_vector.at(6) <= 0.0) {
											if (feature_vector.at(2) <= 13.14) {
												return 0;
											}
											else {
												return 0;
											}
										}
										else {
											if (feature_vector.at(2) <= 19.29) {
												return 0;
											}
											else {
												return 0;
											}
										}
									}
								}
								else {
									if (feature_vector.at(0) <= 2.5) {
										return 0;
									}
									else {
										if (feature_vector.at(2) <= 8.36) {
											return 0;
										}
										else {
											return 1;
										}
									}
								}
							}
							else {
								if (feature_vector.at(11) <= 21.98) {
									return 1;
								}
								else {
									if (feature_vector.at(2) <= 35.69) {
										if (feature_vector.at(6) <= 0.0) {
											return 1;
										}
										else {
											if (feature_vector.at(12) <= 149.5) {
												return 0;
											}
											else {
												return 0;
											}
										}
									}
									else {
										return 0;
									}
								}
							}
						}
					}
					else {
						if (feature_vector.at(11) <= 4.15) {
							if (feature_vector.at(2) <= 5.63) {
								if (feature_vector.at(12) <= 24.5) {
									return 1;
								}
								else {
									if (feature_vector.at(11) <= 2.63) {
										return 0;
									}
									else {
										return 0;
									}
								}
							}
							else {
								return 1;
							}
						}
						else {
							if (feature_vector.at(7) <= 7.5) {
								if (feature_vector.at(11) <= 9.16) {
									if (feature_vector.at(2) <= 7.99) {
										if (feature_vector.at(12) <= 31.5) {
											return 0;
										}
										else {
											return 0;
										}
									}
									else {
										if (feature_vector.at(2) <= 14.79) {
											return 0;
										}
										else {
											return 1;
										}
									}
								}
								else {
									if (feature_vector.at(2) <= 15.34) {
										if (feature_vector.at(9) <= 0.84) {
											if (feature_vector.at(12) <= 90.5) {
												return 0;
											}
											else {
												return 0;
											}
										}
										else {
											if (feature_vector.at(8) <= 0.77) {
												return 0;
											}
											else {
												return 0;
											}
										}
									}
									else {
										if (feature_vector.at(11) <= 14.39) {
											return 0;
										}
										else {
											if (feature_vector.at(1) <= 1148465.0) {
												return 0;
											}
											else {
												return 1;
											}
										}
									}
								}
							}
							else {
								if (feature_vector.at(12) <= 118.5) {
									if (feature_vector.at(2) <= 8.2) {
										if (feature_vector.at(8) <= 0.48) {
											return 0;
										}
										else {
											if (feature_vector.at(9) <= 0.83) {
												return 0;
											}
											else {
												return 0;
											}
										}
									}
									else {
										if (feature_vector.at(11) <= 8.55) {
											return 1;
										}
										else {
											if (feature_vector.at(6) <= 0.0) {
												return 0;
											}
											else {
												return 0;
											}
										}
									}
								}
								else {
									if (feature_vector.at(1) <= 1569.0) {
										return 0;
									}
									else {
										if (feature_vector.at(2) <= 16.38) {
											return 0;
										}
										else {
											if (feature_vector.at(12) <= 164.5) {
												return 0;
											}
											else {
												return 0;
											}
										}
									}
								}
							}
						}
					}
				}
			}
			else {
				if (feature_vector.at(8) <= 0.9) {
					if (feature_vector.at(7) <= 7.5) {
						if (feature_vector.at(11) <= 4.07) {
							if (feature_vector.at(2) <= 4.02) {
								if (feature_vector.at(12) <= 18.5) {
									if (feature_vector.at(5) <= 2.5) {
										return 0;
									}
									else {
										return 0;
									}
								}
								else {
									if (feature_vector.at(2) <= 2.67) {
										return 0;
									}
									else {
										return 0;
									}
								}
							}
							else {
								if (feature_vector.at(0) <= 4.5) {
									return 0;
								}
								else {
									return 1;
								}
							}
						}
						else {
							if (feature_vector.at(2) <= 5.37) {
								if (feature_vector.at(12) <= 42.5) {
									return 0;
								}
								else {
									return 0;
								}
							}
							else {
								if (feature_vector.at(8) <= 0.5) {
									return 0;
								}
								else {
									if (feature_vector.at(1) <= 1569.0) {
										return 0;
									}
									else {
										if (feature_vector.at(9) <= 0.7) {
											return 0;
										}
										else {
											return 0;
										}
									}
								}
							}
						}
					}
					else {
						if (feature_vector.at(1) <= 17.0) {
							if (feature_vector.at(8) <= 0.5) {
								return 0;
							}
							else {
								return 0;
							}
						}
						else {
							if (feature_vector.at(7) <= 9.5) {
								if (feature_vector.at(12) <= 84.5) {
									return 0;
								}
								else {
									return 0;
								}
							}
							else {
								return 0;
							}
						}
					}
				}
				else {
					if (feature_vector.at(11) <= 6.85) {
						if (feature_vector.at(2) <= 5.67) {
							if (feature_vector.at(11) <= 3.7) {
								return 0;
							}
							else {
								return 0;
							}
						}
						else {
							if (feature_vector.at(11) <= 4.12) {
								return 0;
							}
							else {
								if (feature_vector.at(2) <= 7.81) {
									return 0;
								}
								else {
									return 0;
								}
							}
						}
					}
					else {
						if (feature_vector.at(2) <= 31.24) {
							if (feature_vector.at(12) <= 127.5) {
								if (feature_vector.at(7) <= 7.5) {
									if (feature_vector.at(2) <= 13.03) {
										return 0;
									}
									else {
										if (feature_vector.at(9) <= 0.48) {
											return 0;
										}
										else {
											return 0;
										}
									}
								}
								else {
									if (feature_vector.at(1) <= 49.0) {
										return 0;
									}
									else {
										if (feature_vector.at(7) <= 9.5) {
											if (feature_vector.at(12) <= 100.5) {
												return 0;
											}
											else {
												return 0;
											}
										}
										else {
											return 0;
										}
									}
								}
							}
							else {
								return 0;
							}
						}
						else {
							if (feature_vector.at(11) <= 25.5) {
								return 0;
							}
							else {
								if (feature_vector.at(2) <= 42.84) {
									return 0;
								}
								else {
									if (feature_vector.at(1) <= 148513.0) {
										return 0;
									}
									else {
										return 1;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	else {
		if (feature_vector.at(1) <= 149041.0) {
			if (feature_vector.at(4) <= 1.5) {
				if (feature_vector.at(12) <= 100.5) {
					if (feature_vector.at(2) <= 7.89) {
						if (feature_vector.at(12) <= 39.5) {
							if (feature_vector.at(2) <= 3.96) {
								if (feature_vector.at(12) <= 20.5) {
									if (feature_vector.at(5) <= 2.5) {
										return 1;
									}
									else {
										if (feature_vector.at(2) <= 2.83) {
											if (feature_vector.at(11) <= 2.01) {
												return 1;
											}
											else {
												return 0;
											}
										}
										else {
											return 1;
										}
									}
								}
								else {
									if (feature_vector.at(8) <= 0.27) {
										if (feature_vector.at(1) <= 19505.0) {
											return 1;
										}
										else {
											return 0;
										}
									}
									else {
										if (feature_vector.at(2) <= 2.8) {
											if (feature_vector.at(6) <= 0.0) {
												return 0;
											}
											else {
												return 1;
											}
										}
										else {
											if (feature_vector.at(11) <= 3.87) {
												return 1;
											}
											else {
												return 0;
											}
										}
									}
								}
							}
							else {
								if (feature_vector.at(11) <= 4.02) {
									return 1;
								}
								else {
									if (feature_vector.at(2) <= 5.74) {
										if (feature_vector.at(5) <= 3.5) {
											return 1;
										}
										else {
											return 1;
										}
									}
									else {
										return 1;
									}
								}
							}
						}
						else {
							if (feature_vector.at(8) <= 0.67) {
								if (feature_vector.at(9) <= 0.82) {
									if (feature_vector.at(5) <= 3.5) {
										if (feature_vector.at(0) <= 3.5) {
											if (feature_vector.at(2) <= 4.77) {
												return 0;
											}
											else {
												return 1;
											}
										}
										else {
											return 1;
										}
									}
									else {
										return 0;
									}
								}
								else {
									if (feature_vector.at(0) <= 2.5) {
										return 1;
									}
									else {
										return 1;
									}
								}
							}
							else {
								if (feature_vector.at(2) <= 4.87) {
									if (feature_vector.at(9) <= 0.81) {
										if (feature_vector.at(2) <= 3.28) {
											return 0;
										}
										else {
											if (feature_vector.at(11) <= 4.82) {
												return 0;
											}
											else {
												return 0;
											}
										}
									}
									else {
										return 0;
									}
								}
								else {
									if (feature_vector.at(11) <= 6.66) {
										return 1;
									}
									else {
										if (feature_vector.at(5) <= 3.5) {
											if (feature_vector.at(12) <= 62.5) {
												return 1;
											}
											else {
												return 0;
											}
										}
										else {
											return 0;
										}
									}
								}
							}
						}
					}
					else {
						if (feature_vector.at(12) <= 65.5) {
							if (feature_vector.at(5) <= 4.5) {
								if (feature_vector.at(6) <= 0.0) {
									if (feature_vector.at(2) <= 11.12) {
										if (feature_vector.at(12) <= 51.5) {
											return 1;
										}
										else {
											return 1;
										}
									}
									else {
										return 1;
									}
								}
								else {
									return 1;
								}
							}
							else {
								return 0;
							}
						}
						else {
							if (feature_vector.at(2) <= 13.47) {
								if (feature_vector.at(5) <= 3.5) {
									if (feature_vector.at(1) <= 49.0) {
										if (feature_vector.at(5) <= 2.5) {
											return 1;
										}
										else {
											return 0;
										}
									}
									else {
										if (feature_vector.at(9) <= 0.79) {
											if (feature_vector.at(1) <= 19505.0) {
												return 1;
											}
											else {
												return 0;
											}
										}
										else {
											return 1;
										}
									}
								}
								else {
									if (feature_vector.at(9) <= 0.71) {
										if (feature_vector.at(1) <= 1569.0) {
											return 0;
										}
										else {
											if (feature_vector.at(11) <= 8.85) {
												return 1;
											}
											else {
												return 0;
											}
										}
									}
									else {
										return 1;
									}
								}
							}
							else {
								if (feature_vector.at(6) <= 0.0) {
									if (feature_vector.at(5) <= 4.5) {
										if (feature_vector.at(2) <= 17.6) {
											return 1;
										}
										else {
											return 1;
										}
									}
									else {
										return 0;
									}
								}
								else {
									if (feature_vector.at(9) <= 0.58) {
										if (feature_vector.at(5) <= 3.5) {
											return 1;
										}
										else {
											if (feature_vector.at(2) <= 18.94) {
												return 0;
											}
											else {
												return 1;
											}
										}
									}
									else {
										return 1;
									}
								}
							}
						}
					}
				}
				else {
					if (feature_vector.at(1) <= 49.0) {
						if (feature_vector.at(5) <= 2.5) {
							return 0;
						}
						else {
							return 0;
						}
					}
					else {
						if (feature_vector.at(2) <= 24.5) {
							if (feature_vector.at(9) <= 0.66) {
								if (feature_vector.at(5) <= 3.5) {
									if (feature_vector.at(0) <= 3.5) {
										if (feature_vector.at(12) <= 134.5) {
											if (feature_vector.at(2) <= 13.98) {
												return 0;
											}
											else {
												return 0;
											}
										}
										else {
											if (feature_vector.at(11) <= 31.67) {
												return 0;
											}
											else {
												return 0;
											}
										}
									}
									else {
										if (feature_vector.at(12) <= 138.5) {
											if (feature_vector.at(2) <= 14.97) {
												return 0;
											}
											else {
												return 1;
											}
										}
										else {
											return 0;
										}
									}
								}
								else {
									if (feature_vector.at(2) <= 18.11) {
										if (feature_vector.at(11) <= 13.26) {
											return 0;
										}
										else {
											return 0;
										}
									}
									else {
										if (feature_vector.at(12) <= 130.5) {
											if (feature_vector.at(6) <= 0.0) {
												return 1;
											}
											else {
												return 0;
											}
										}
										else {
											return 0;
										}
									}
								}
							}
							else {
								if (feature_vector.at(12) <= 136.5) {
									if (feature_vector.at(2) <= 15.58) {
										if (feature_vector.at(5) <= 3.5) {
											return 1;
										}
										else {
											return 0;
										}
									}
									else {
										return 1;
									}
								}
								else {
									if (feature_vector.at(5) <= 3.5) {
										if (feature_vector.at(9) <= 0.95) {
											return 0;
										}
										else {
											return 1;
										}
									}
									else {
										return 0;
									}
								}
							}
						}
						else {
							if (feature_vector.at(1) <= 1569.0) {
								if (feature_vector.at(5) <= 3.5) {
									return 0;
								}
								else {
									return 0;
								}
							}
							else {
								if (feature_vector.at(6) <= 0.0) {
									return 1;
								}
								else {
									if (feature_vector.at(5) <= 4.5) {
										if (feature_vector.at(12) <= 142.5) {
											if (feature_vector.at(6) <= 0.0) {
												return 1;
											}
											else {
												return 1;
											}
										}
										else {
											if (feature_vector.at(2) <= 43.57) {
												return 1;
											}
											else {
												return 1;
											}
										}
									}
									else {
										if (feature_vector.at(1) <= 50209.0) {
											return 0;
										}
										else {
											return 1;
										}
									}
								}
							}
						}
					}
				}
			}
			else {
				if (feature_vector.at(1) <= 49.0) {
					if (feature_vector.at(12) <= 86.5) {
						if (feature_vector.at(5) <= 2.5) {
							if (feature_vector.at(12) <= 47.5) {
								return 1;
							}
							else {
								if (feature_vector.at(2) <= 5.13) {
									return 1;
								}
								else {
									return 1;
								}
							}
						}
						else {
							if (feature_vector.at(12) <= 37.5) {
								return 1;
							}
							else {
								return 0;
							}
						}
					}
					else {
						if (feature_vector.at(5) <= 2.5) {
							if (feature_vector.at(12) <= 113.5) {
								return 0;
							}
							else {
								return 0;
							}
						}
						else {
							return 0;
						}
					}
				}
				else {
					if (feature_vector.at(5) <= 4.5) {
						if (feature_vector.at(12) <= 76.5) {
							if (feature_vector.at(5) <= 3.5) {
								if (feature_vector.at(8) <= 0.37) {
									if (feature_vector.at(1) <= 145.0) {
										return 1;
									}
									else {
										if (feature_vector.at(6) <= 0.0) {
											return 1;
										}
										else {
											return 1;
										}
									}
								}
								else {
									if (feature_vector.at(2) <= 5.69) {
										if (feature_vector.at(10) <= 39.39) {
											return 1;
										}
										else {
											if (feature_vector.at(6) <= 0.0) {
												return 1;
											}
											else {
												return 1;
											}
										}
									}
									else {
										if (feature_vector.at(12) <= 55.5) {
											return 1;
										}
										else {
											if (feature_vector.at(2) <= 9.97) {
												return 1;
											}
											else {
												return 1;
											}
										}
									}
								}
							}
							else {
								if (feature_vector.at(1) <= 1569.0) {
									if (feature_vector.at(12) <= 32.5) {
										return 1;
									}
									else {
										return 0;
									}
								}
								else {
									if (feature_vector.at(2) <= 7.71) {
										if (feature_vector.at(12) <= 42.5) {
											if (feature_vector.at(10) <= 51.98) {
												return 1;
											}
											else {
												return 1;
											}
										}
										else {
											if (feature_vector.at(9) <= 0.8) {
												return 0;
											}
											else {
												return 1;
											}
										}
									}
									else {
										if (feature_vector.at(6) <= 0.0) {
											if (feature_vector.at(12) <= 49.5) {
												return 1;
											}
											else {
												return 1;
											}
										}
										else {
											if (feature_vector.at(7) <= 6.5) {
												return 1;
											}
											else {
												return 1;
											}
										}
									}
								}
							}
						}
						else {
							if (feature_vector.at(1) <= 1569.0) {
								if (feature_vector.at(5) <= 3.5) {
									if (feature_vector.at(12) <= 132.5) {
										if (feature_vector.at(1) <= 609.0) {
											return 1;
										}
										else {
											if (feature_vector.at(7) <= 7.5) {
												return 1;
											}
											else {
												return 1;
											}
										}
									}
									else {
										return 0;
									}
								}
								else {
									return 0;
								}
							}
							else {
								if (feature_vector.at(2) <= 16.81) {
									if (feature_vector.at(12) <= 121.5) {
										if (feature_vector.at(1) <= 19505.0) {
											if (feature_vector.at(2) <= 7.69) {
												return 1;
											}
											else {
												return 1;
											}
										}
										else {
											if (feature_vector.at(9) <= 0.59) {
												return 1;
											}
											else {
												return 1;
											}
										}
									}
									else {
										if (feature_vector.at(1) <= 19505.0) {
											if (feature_vector.at(2) <= 13.14) {
												return 0;
											}
											else {
												return 1;
											}
										}
										else {
											if (feature_vector.at(9) <= 0.82) {
												return 0;
											}
											else {
												return 1;
											}
										}
									}
								}
								else {
									if (feature_vector.at(6) <= 0.0) {
										if (feature_vector.at(6) <= 0.0) {
											if (feature_vector.at(2) <= 21.79) {
												return 1;
											}
											else {
												return 1;
											}
										}
										else {
											if (feature_vector.at(6) <= 0.0) {
												return 1;
											}
											else {
												return 1;
											}
										}
									}
									else {
										if (feature_vector.at(6) <= 0.0) {
											return 1;
										}
										else {
											if (feature_vector.at(0) <= 1.5) {
												return 1;
											}
											else {
												return 1;
											}
										}
									}
								}
							}
						}
					}
					else {
						if (feature_vector.at(1) <= 50209.0) {
							if (feature_vector.at(12) <= 50.5) {
								return 1;
							}
							else {
								if (feature_vector.at(1) <= 1569.0) {
									return 0;
								}
								else {
									return 0;
								}
							}
						}
						else {
							if (feature_vector.at(2) <= 24.93) {
								if (feature_vector.at(12) <= 110.5) {
									if (feature_vector.at(2) <= 10.71) {
										return 0;
									}
									else {
										return 1;
									}
								}
								else {
									return 0;
								}
							}
							else {
								return 1;
							}
						}
					}
				}
			}
		}
		else {
			if (feature_vector.at(2) <= 0.44) {
				return 1;
			}
			else {
				return 1;
			}
		}
	}
}