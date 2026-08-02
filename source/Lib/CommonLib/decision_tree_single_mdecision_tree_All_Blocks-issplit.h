
/*
This inline function was automatically generated using DecisionTreeToCpp Converter

It takes feature vector as single argument:
feature_vector[0] - inter_cost
feature_vector[1] - cs_inter_had
feature_vector[2] - ref_line_variance
feature_vector[3] - ref_line_range
feature_vector[4] - num_intra_ciip_neighbors
feature_vector[5] - var_mismatch
feature_vector[6] - dist_center_y
feature_vector[7] - splitting_density
feature_vector[8] - blk_max
feature_vector[9] - blk_range


It returns index of predicted class:
0 - 0
1 - 1


Simply include this file to your project and use it
*/

#include <vector>

inline int decision_tree_single_mdecision_tree_All_Blocks_issplit(const std::vector<double> & feature_vector) 
{
	if (feature_vector.at(7) <= 0.17) {
		if (feature_vector.at(0) <= 2132840.0) {
			if (feature_vector.at(0) <= 1767080.0) {
				if (feature_vector.at(0) <= 1509015.0) {
					if (feature_vector.at(0) <= 1380285.0) {
						return 0;
					}
					else {
						if (feature_vector.at(1) <= 3126.5) {
							return 0;
						}
						else {
							return 0;
						}
					}
				}
				else {
					if (feature_vector.at(1) <= 480.5) {
						if (feature_vector.at(4) <= 1.5) {
							return 0;
						}
						else {
							if (feature_vector.at(1) <= 171.0) {
								return 0;
							}
							else {
								return 0;
							}
						}
					}
					else {
						if (feature_vector.at(4) <= 0.5) {
							if (feature_vector.at(0) <= 1646360.0) {
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
				if (feature_vector.at(1) <= 584.5) {
					if (feature_vector.at(0) <= 1890045.0) {
						return 0;
					}
					else {
						if (feature_vector.at(8) <= 45.5) {
							return 0;
						}
						else {
							if (feature_vector.at(4) <= 1.5) {
								if (feature_vector.at(0) <= 2095640.0) {
									if (feature_vector.at(1) <= 463.5) {
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
								if (feature_vector.at(5) <= 47.24) {
									if (feature_vector.at(1) <= 214.5) {
										return 0;
									}
									else {
										if (feature_vector.at(9) <= 19.5) {
											return 0;
										}
										else {
											return 0;
										}
									}
								}
								else {
									if (feature_vector.at(6) <= 0.24) {
										return 1;
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
					if (feature_vector.at(4) <= 0.5) {
						if (feature_vector.at(0) <= 1915060.0) {
							if (feature_vector.at(0) <= 1852655.0) {
								return 0;
							}
							else {
								if (feature_vector.at(9) <= 35.5) {
									return 0;
								}
								else {
									return 1;
								}
							}
						}
						else {
							if (feature_vector.at(9) <= 23.5) {
								return 0;
							}
							else {
								if (feature_vector.at(1) <= 7425.5) {
									if (feature_vector.at(0) <= 2015835.0) {
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
						}
					}
					else {
						if (feature_vector.at(0) <= 1958635.0) {
							if (feature_vector.at(4) <= 1.5) {
								return 0;
							}
							else {
								return 0;
							}
						}
						else {
							if (feature_vector.at(4) <= 1.5) {
								return 0;
							}
							else {
								if (feature_vector.at(9) <= 26.5) {
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
			if (feature_vector.at(0) <= 3668230.0) {
				if (feature_vector.at(9) <= 42.5) {
					if (feature_vector.at(0) <= 2645340.0) {
						if (feature_vector.at(9) <= 20.5) {
							if (feature_vector.at(5) <= 43.84) {
								if (feature_vector.at(1) <= 160.5) {
									return 1;
								}
								else {
									if (feature_vector.at(9) <= 13.5) {
										return 0;
									}
									else {
										if (feature_vector.at(1) <= 2035.5) {
											if (feature_vector.at(1) <= 405.0) {
												return 0;
											}
											else {
												if (feature_vector.at(4) <= 1.5) {
													return 1;
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
							else {
								return 1;
							}
						}
						else {
							if (feature_vector.at(8) <= 50.5) {
								if (feature_vector.at(1) <= 562.5) {
									return 0;
								}
								else {
									if (feature_vector.at(1) <= 1773.0) {
										return 1;
									}
									else {
										return 0;
									}
								}
							}
							else {
								if (feature_vector.at(0) <= 2349890.0) {
									if (feature_vector.at(2) <= 1.14) {
										return 1;
									}
									else {
										if (feature_vector.at(1) <= 729.5) {
											return 0;
										}
										else {
											if (feature_vector.at(1) <= 1846.0) {
												if (feature_vector.at(4) <= 1.5) {
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
									if (feature_vector.at(1) <= 5024.5) {
										if (feature_vector.at(4) <= 0.5) {
											if (feature_vector.at(1) <= 554.5) {
												return 1;
											}
											else {
												if (feature_vector.at(1) <= 2630.0) {
													return 1;
												}
												else {
													return 1;
												}
											}
										}
										else {
											if (feature_vector.at(3) <= 32.5) {
												if (feature_vector.at(1) <= 348.5) {
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
										return 0;
									}
								}
							}
						}
					}
					else {
						if (feature_vector.at(8) <= 48.5) {
							if (feature_vector.at(2) <= 58.03) {
								if (feature_vector.at(0) <= 3293545.0) {
									if (feature_vector.at(4) <= 0.5) {
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
							else {
								return 1;
							}
						}
						else {
							if (feature_vector.at(1) <= 3520.5) {
								if (feature_vector.at(9) <= 22.5) {
									if (feature_vector.at(4) <= 1.5) {
										if (feature_vector.at(1) <= 959.0) {
											if (feature_vector.at(1) <= 321.5) {
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
										if (feature_vector.at(1) <= 619.5) {
											if (feature_vector.at(5) <= 26.28) {
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
								}
								else {
									if (feature_vector.at(2) <= 3.14) {
										if (feature_vector.at(4) <= 0.5) {
											return 1;
										}
										else {
											return 1;
										}
									}
									else {
										if (feature_vector.at(0) <= 3081265.0) {
											return 1;
										}
										else {
											return 1;
										}
									}
								}
							}
							else {
								if (feature_vector.at(5) <= 28.02) {
									if (feature_vector.at(0) <= 2838355.0) {
										return 0;
									}
									else {
										return 0;
									}
								}
								else {
									if (feature_vector.at(4) <= 1.5) {
										return 1;
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
					if (feature_vector.at(0) <= 2549480.0) {
						if (feature_vector.at(4) <= 0.5) {
							if (feature_vector.at(1) <= 657.5) {
								if (feature_vector.at(1) <= 278.5) {
									if (feature_vector.at(0) <= 2359100.0) {
										return 0;
									}
									else {
										return 0;
									}
								}
								else {
									if (feature_vector.at(0) <= 2270360.0) {
										return 0;
									}
									else {
										if (feature_vector.at(6) <= 0.42) {
											return 1;
										}
										else {
											if (feature_vector.at(2) <= 6.93) {
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
								if (feature_vector.at(1) <= 7908.5) {
									if (feature_vector.at(0) <= 2332675.0) {
										return 1;
									}
									else {
										if (feature_vector.at(1) <= 960.5) {
											return 1;
										}
										else {
											if (feature_vector.at(6) <= 0.69) {
												return 1;
											}
											else {
												return 1;
											}
										}
									}
								}
								else {
									if (feature_vector.at(9) <= 63.5) {
										return 0;
									}
									else {
										if (feature_vector.at(1) <= 11144.5) {
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
							if (feature_vector.at(0) <= 2315085.0) {
								if (feature_vector.at(4) <= 1.5) {
									if (feature_vector.at(1) <= 908.0) {
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
								if (feature_vector.at(9) <= 65.5) {
									if (feature_vector.at(1) <= 5048.0) {
										if (feature_vector.at(6) <= 0.55) {
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
									if (feature_vector.at(0) <= 2428220.0) {
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
						if (feature_vector.at(1) <= 913.5) {
							if (feature_vector.at(1) <= 334.5) {
								if (feature_vector.at(2) <= 3.21) {
									return 1;
								}
								else {
									return 1;
								}
							}
							else {
								if (feature_vector.at(0) <= 2934110.0) {
									return 1;
								}
								else {
									if (feature_vector.at(9) <= 132.5) {
										return 1;
									}
									else {
										if (feature_vector.at(2) <= 3279.4) {
											if (feature_vector.at(3) <= 21.5) {
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
						}
						else {
							if (feature_vector.at(4) <= 0.5) {
								if (feature_vector.at(1) <= 21826.5) {
									if (feature_vector.at(1) <= 10576.5) {
										if (feature_vector.at(0) <= 3172985.0) {
											if (feature_vector.at(1) <= 1212.5) {
												return 1;
											}
											else {
												if (feature_vector.at(9) <= 56.5) {
													if (feature_vector.at(1) <= 4693.0) {
														return 1;
													}
													else {
														if (feature_vector.at(5) <= 72.55) {
															return 1;
														}
														else {
															return 1;
														}
													}
												}
												else {
													if (feature_vector.at(6) <= 0.73) {
														return 1;
													}
													else {
														return 1;
													}
												}
											}
										}
										else {
											if (feature_vector.at(1) <= 1416.5) {
												return 1;
											}
											else {
												if (feature_vector.at(9) <= 55.5) {
													return 1;
												}
												else {
													return 1;
												}
											}
										}
									}
									else {
										if (feature_vector.at(0) <= 3250455.0) {
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
								if (feature_vector.at(0) <= 2988555.0) {
									if (feature_vector.at(1) <= 6411.0) {
										if (feature_vector.at(4) <= 1.5) {
											return 1;
										}
										else {
											if (feature_vector.at(1) <= 2045.5) {
												return 1;
											}
											else {
												return 1;
											}
										}
									}
									else {
										if (feature_vector.at(8) <= 109.5) {
											return 0;
										}
										else {
											return 1;
										}
									}
								}
								else {
									if (feature_vector.at(1) <= 6201.0) {
										if (feature_vector.at(9) <= 54.5) {
											return 1;
										}
										else {
											return 1;
										}
									}
									else {
										if (feature_vector.at(9) <= 66.5) {
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
			}
			else {
				if (feature_vector.at(9) <= 46.5) {
					if (feature_vector.at(8) <= 44.5) {
						if (feature_vector.at(0) <= 20233450.0) {
							if (feature_vector.at(2) <= 28.71) {
								if (feature_vector.at(0) <= 5493870.0) {
									if (feature_vector.at(1) <= 1048.5) {
										if (feature_vector.at(9) <= 18.5) {
											return 1;
										}
										else {
											return 1;
										}
									}
									else {
										if (feature_vector.at(4) <= 1.5) {
											return 0;
										}
										else {
											return 0;
										}
									}
								}
								else {
									if (feature_vector.at(4) <= 0.5) {
										return 1;
									}
									else {
										if (feature_vector.at(9) <= 24.5) {
											if (feature_vector.at(0) <= 7355505.0) {
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
								return 1;
							}
						}
						else {
							return 1;
						}
					}
					else {
						if (feature_vector.at(0) <= 6255970.0) {
							if (feature_vector.at(5) <= 14.95) {
								if (feature_vector.at(4) <= 1.5) {
									if (feature_vector.at(1) <= 3364.5) {
										if (feature_vector.at(8) <= 47.5) {
											return 1;
										}
										else {
											return 1;
										}
									}
									else {
										if (feature_vector.at(2) <= 36.89) {
											if (feature_vector.at(0) <= 4802725.0) {
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
								else {
									if (feature_vector.at(2) <= 13.89) {
										if (feature_vector.at(1) <= 869.0) {
											return 1;
										}
										else {
											if (feature_vector.at(0) <= 5077495.0) {
												return 0;
											}
											else {
												return 1;
											}
										}
									}
									else {
										if (feature_vector.at(1) <= 3801.5) {
											return 1;
										}
										else {
											return 0;
										}
									}
								}
							}
							else {
								if (feature_vector.at(1) <= 4364.0) {
									if (feature_vector.at(4) <= 1.5) {
										if (feature_vector.at(2) <= 1.82) {
											return 1;
										}
										else {
											return 1;
										}
									}
									else {
										if (feature_vector.at(1) <= 1650.5) {
											return 1;
										}
										else {
											if (feature_vector.at(9) <= 28.5) {
												return 0;
											}
											else {
												return 1;
											}
										}
									}
								}
								else {
									if (feature_vector.at(0) <= 4760985.0) {
										return 1;
									}
									else {
										return 1;
									}
								}
							}
						}
						else {
							if (feature_vector.at(1) <= 17609.0) {
								if (feature_vector.at(0) <= 9066370.0) {
									if (feature_vector.at(5) <= 10.18) {
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
								if (feature_vector.at(0) <= 13781800.0) {
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
					if (feature_vector.at(0) <= 7017355.0) {
						if (feature_vector.at(1) <= 25510.5) {
							if (feature_vector.at(1) <= 1230.5) {
								if (feature_vector.at(4) <= 0.5) {
									if (feature_vector.at(9) <= 165.5) {
										if (feature_vector.at(1) <= 448.5) {
											return 1;
										}
										else {
											if (feature_vector.at(6) <= 0.79) {
												if (feature_vector.at(2) <= 8.22) {
													return 1;
												}
												else {
													if (feature_vector.at(9) <= 112.5) {
														return 1;
													}
													else {
														return 1;
													}
												}
											}
											else {
												if (feature_vector.at(0) <= 5059425.0) {
													return 1;
												}
												else {
													return 1;
												}
											}
										}
									}
									else {
										if (feature_vector.at(1) <= 768.5) {
											if (feature_vector.at(3) <= 31.5) {
												return 1;
											}
											else {
												if (feature_vector.at(8) <= 215.5) {
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
								else {
									if (feature_vector.at(0) <= 4505380.0) {
										return 1;
									}
									else {
										return 1;
									}
								}
							}
							else {
								if (feature_vector.at(9) <= 73.5) {
									if (feature_vector.at(1) <= 18874.0) {
										if (feature_vector.at(4) <= 1.5) {
											if (feature_vector.at(0) <= 4487905.0) {
												if (feature_vector.at(1) <= 8448.0) {
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
											if (feature_vector.at(1) <= 6615.5) {
												if (feature_vector.at(0) <= 4647460.0) {
													return 1;
												}
												else {
													return 1;
												}
											}
											else {
												if (feature_vector.at(0) <= 3995330.0) {
													return 0;
												}
												else {
													if (feature_vector.at(8) <= 77.5) {
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
										return 1;
									}
								}
								else {
									if (feature_vector.at(0) <= 5132660.0) {
										if (feature_vector.at(4) <= 0.5) {
											if (feature_vector.at(1) <= 18300.5) {
												if (feature_vector.at(1) <= 1730.5) {
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
											if (feature_vector.at(1) <= 12353.5) {
												return 1;
											}
											else {
												return 1;
											}
										}
									}
									else {
										if (feature_vector.at(1) <= 1795.5) {
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
							if (feature_vector.at(8) <= 140.5) {
								if (feature_vector.at(0) <= 4953965.0) {
									return 0;
								}
								else {
									if (feature_vector.at(2) <= 30.53) {
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
					else {
						if (feature_vector.at(0) <= 14319350.0) {
							if (feature_vector.at(8) <= 56.5) {
								return 1;
							}
							else {
								if (feature_vector.at(9) <= 72.5) {
									if (feature_vector.at(1) <= 21270.5) {
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
						else {
							return 1;
						}
					}
				}
			}
		}
	}
	else {
		if (feature_vector.at(6) <= 0.95) {
			if (feature_vector.at(0) <= 43913600.0) {
				if (feature_vector.at(6) <= 0.87) {
					return 0;
				}
				else {
					if (feature_vector.at(1) <= 11335.5) {
						if (feature_vector.at(6) <= 0.87) {
							if (feature_vector.at(1) <= 4929.5) {
								return 0;
							}
							else {
								if (feature_vector.at(0) <= 11701600.0) {
									if (feature_vector.at(8) <= 190.5) {
										if (feature_vector.at(3) <= 52.5) {
											return 0;
										}
										else {
											if (feature_vector.at(1) <= 6901.5) {
												return 1;
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
									return 1;
								}
							}
						}
						else {
							if (feature_vector.at(0) <= 17990600.0) {
								return 0;
							}
							else {
								if (feature_vector.at(6) <= 0.92) {
									return 0;
								}
								else {
									if (feature_vector.at(6) <= 0.93) {
										return 0;
									}
									else {
										return 0;
									}
								}
							}
						}
					}
					else {
						if (feature_vector.at(3) <= 27.5) {
							return 0;
						}
						else {
							if (feature_vector.at(0) <= 13219600.0) {
								if (feature_vector.at(6) <= 0.92) {
									if (feature_vector.at(6) <= 0.87) {
										if (feature_vector.at(5) <= 403.01) {
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
									if (feature_vector.at(7) <= 0.42) {
										if (feature_vector.at(1) <= 13474.5) {
											return 0;
										}
										else {
											if (feature_vector.at(9) <= 100.5) {
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
							}
							else {
								return 1;
							}
						}
					}
				}
			}
			else {
				if (feature_vector.at(6) <= 0.76) {
					if (feature_vector.at(1) <= 16322.0) {
						return 0;
					}
					else {
						return 0;
					}
				}
				else {
					if (feature_vector.at(9) <= 197.5) {
						if (feature_vector.at(3) <= 30.0) {
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
			}
		}
		else {
			if (feature_vector.at(0) <= 3587205.0) {
				if (feature_vector.at(0) <= 2250370.0) {
					if (feature_vector.at(0) <= 1745485.0) {
						return 0;
					}
					else {
						return 0;
					}
				}
				else {
					if (feature_vector.at(3) <= 15.5) {
						if (feature_vector.at(2) <= 0.27) {
							return 0;
						}
						else {
							return 0;
						}
					}
					else {
						if (feature_vector.at(6) <= 0.97) {
							return 0;
						}
						else {
							if (feature_vector.at(7) <= 0.75) {
								if (feature_vector.at(6) <= 0.99) {
									if (feature_vector.at(6) <= 0.98) {
										if (feature_vector.at(3) <= 48.5) {
											return 0;
										}
										else {
											if (feature_vector.at(0) <= 2527930.0) {
												return 0;
											}
											else {
												if (feature_vector.at(7) <= 0.42) {
													if (feature_vector.at(4) <= 0.5) {
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
										return 0;
									}
								}
								else {
									if (feature_vector.at(6) <= 0.99) {
										if (feature_vector.at(9) <= 82.5) {
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
							}
							else {
								if (feature_vector.at(7) <= 1.08) {
									if (feature_vector.at(1) <= 1511.0) {
										return 0;
									}
									else {
										if (feature_vector.at(6) <= 0.99) {
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
			}
			else {
				if (feature_vector.at(3) <= 10.5) {
					if (feature_vector.at(2) <= 0.36) {
						return 0;
					}
					else {
						if (feature_vector.at(6) <= 0.98) {
							return 0;
						}
						else {
							if (feature_vector.at(7) <= 0.75) {
								if (feature_vector.at(4) <= 0.5) {
									if (feature_vector.at(8) <= 147.0) {
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
								return 0;
							}
						}
					}
				}
				else {
					if (feature_vector.at(7) <= 1.08) {
						if (feature_vector.at(1) <= 5991.5) {
							if (feature_vector.at(6) <= 0.97) {
								if (feature_vector.at(0) <= 16542550.0) {
									if (feature_vector.at(6) <= 0.96) {
										if (feature_vector.at(1) <= 3516.0) {
											return 0;
										}
										else {
											if (feature_vector.at(8) <= 177.5) {
												if (feature_vector.at(7) <= 0.5) {
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
									else {
										return 0;
									}
								}
								else {
									return 1;
								}
							}
							else {
								if (feature_vector.at(6) <= 0.99) {
									if (feature_vector.at(6) <= 0.99) {
										if (feature_vector.at(6) <= 0.98) {
											if (feature_vector.at(9) <= 125.5) {
												if (feature_vector.at(0) <= 8688095.0) {
													if (feature_vector.at(3) <= 32.5) {
														if (feature_vector.at(6) <= 0.98) {
															return 0;
														}
														else {
															return 0;
														}
													}
													else {
														if (feature_vector.at(1) <= 3062.5) {
															return 0;
														}
														else {
															return 1;
														}
													}
												}
												else {
													if (feature_vector.at(7) <= 0.75) {
														return 1;
													}
													else {
														return 0;
													}
												}
											}
											else {
												if (feature_vector.at(4) <= 0.5) {
													if (feature_vector.at(7) <= 0.75) {
														if (feature_vector.at(9) <= 158.5) {
															if (feature_vector.at(8) <= 198.5) {
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
														if (feature_vector.at(1) <= 2493.0) {
															return 0;
														}
														else {
															if (feature_vector.at(0) <= 8092670.0) {
																return 1;
															}
															else {
																return 1;
															}
														}
													}
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
										if (feature_vector.at(3) <= 36.5) {
											if (feature_vector.at(7) <= 0.75) {
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
									return 0;
								}
							}
						}
						else {
							if (feature_vector.at(7) <= 0.75) {
								if (feature_vector.at(0) <= 8447505.0) {
									if (feature_vector.at(3) <= 42.5) {
										return 1;
									}
									else {
										if (feature_vector.at(1) <= 7882.5) {
											if (feature_vector.at(6) <= 0.97) {
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
								}
								else {
									return 1;
								}
							}
							else {
								if (feature_vector.at(6) <= 0.97) {
									return 0;
								}
								else {
									if (feature_vector.at(9) <= 180.5) {
										if (feature_vector.at(2) <= 1179.28) {
											if (feature_vector.at(6) <= 0.99) {
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
										return 1;
									}
								}
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
}
