# ASSIGNMENT 1
### NAME: ZAEENA AFTAB
### SECTION: BS(AI)-1A
### ROLL NO: 26K-0011
<br><br>
# PART B - QUESTION 1
## *Hotel Booking System* 
<br><br>
### **IPO CHARTS**
| Input | Process | Output |
|---|---|---|
| Number of guests (N) | Loop through all N guests | Guest booking details |
| Season (Peak / Off-Peak) | Determine the applicable season rate | Selected room rate |
| Room Type (Standard / Deluxe / Suite) | Determine the base rate according to room type and season | Base rate per night |
| Number of nights |`rate × nights` | Initial total price |
| Number of nights | If nights > 7, apply 15% discount | Discounted total price |
| Guest's total price | Add the price to running hotel revenue | Hotel Total Revenue |

### **PAC CHART**
| Problem | Analysis and Solution |
|---|---|
| Process N guests | Use a loop that runs N times |
| Determine room rate | Use nested decision-making based on season and room type |
| Peak Season | Standard = Rs. 5,000, Deluxe = Rs. 8,000, Suite = Rs. 12,000 |
| Off-Peak Season | Standard = Rs. 3,000, Deluxe = Rs. 5,000, Suite = Rs. 8,000 |
| Calculate guest price | `Total = Rate × Nights` |
| Long-stay discount | If nights > 7, apply a 15% discount |
| Calculate final price | `Final Price = Total − Discount` |
| Calculate hotel revenue | `Revenue = Final price + Revenue` |
| Final output | Display each guest's final price and total hotel revenue |

<br><br>
# PART B - QUESTION 2
## *Elevator Simulation* 
<br><br>
### **IPO CHARTS**
| Input | Process | Output |
|---|---|---|
| Total Requests | Loop through all Requests | Direction of movement |
| Final Floor | Compare with Current floor | |

<br><br>

### **PAC CHART**
| Problem | Analysis and Solution |
|---|---|
| Initialize elevator | Set the current floor to 0 |
| Process requests | Use a loop to process all N floor requests |
| Request above current floor | If requested floor > current floor, display "Moving Up" |
| Request below current floor | If requested floor < current floor, display "Moving Down" |
| Request at current floor | If requested floor = current floor, display "Doors Opening" |
| Update elevator position | Set current floor equal to the requested floor |
| Repeat process | Continue until all N requests have been processed |

<br><br>
# PART B - QUESTION 3
## *Class Result Processing*
<br><br>
### **IPO CHART**
| Input | Process | Output |
|---|---|---|
| Number of Students (N) | Loop through all N students | Student result |
| 5 Subject Marks | Use an inner loop to input all 5 marks | Sum of marks |
| Subject Marks | `Average = Sum / 5` | Average |
| Average | If average >= 80, classify as Distinction | "Distinction" |
| Average | If average >= 60, classify as Pass | "Pass" |
| Average | If average < 60, classify as Fail | "Fail" |
| Individual Subject Marks | If any mark < 33, terminate loop | "Fail — Subject Deficiency" |

<br><br>

### **PAC CHART**
| Problem | Analysis and Solution |
|---|---|
| Process N students | Use an outer loop that runs N times |
| Process 5 subjects | Use an inner loop to process 5 marks for each student |
| Calculate total marks | Add all 5 subject marks to obtain the sum |
| Calculate average | `Average = Sum / 5` |
| Determine Distinction | If average >= 80, display "Distinction" |
| Determine Pass | If average >= 60 and average < 80, display "Pass" |
| Determine Fail | If average < 60, display "Fail" |
| Check subject deficiency | If any individual mark < 33, terminate loop |
| Subject Deficiency Result | Display "Fail — Subject Deficiency" |
| Repeat for all students | Continue the outer loop until all N students are processed |

<br><br>
# PART B - QUESTION 4
## *Online Shopping Bill Calculator*
<br><br>
### **IPO CHART**
| Input | Process | Output |
| --- | --- | --- |
| Quantity (q) | | |
| Price per Item (p) | Calculate Subtotal: `s = q × p` | Subtotal |
| Discount Percentage (d) | Calculate Discounted Amount: `a = s − (s × d) / 100` | Discounted Amount |
| Tax Percentage (t) | Calculate Final Bill: `Final Bill = a + (a × t) / 100` | Final Bill |
| Quantity, Price, Discount, Tax | Validate all entered values | Error message if invalid |
| Calculation Details | Store calculation details and generate bill document | Bill Document |
| Final Bill | Display the final bill to the customer | Final Bill Display |

<br><br>

### **PAC CHART**
| Problem | Analysis and Solution |
|---|---|
| Get quantity | Ask the customer to enter the quantity purchased |
| Get price | Ask for the price per item |
| Get discount | Ask for the discount percentage |
| Get tax | Ask for the tax percentage |
| Validate inputs | Check whether all entered values are valid |
| Handle invalid input | If any value is invalid, display an error message and terminate |
| Calculate subtotal | `s = q × p` |
| Calculate discounted amount | `a = s − (s × d) / 100` |
| Calculate final bill | `Final Bill = a + (a × t) / 100` |
| Store details | Store the calculation details |
| Generate bill | Generate a bill document containing the calculation details |
| Display result | Display the final bill to the customer |

<br><br>
# PART B - QUESTION 5
##  *Smart Campus Parking and Access Management System*
<br><br>
### **IPO CHART**
| Input | Process | Output |
|---|---|---|
| Number of Vehicles | Loop through all vehicles | Total Vehicles Processed |
| Vehicle Type (C/B/V) | Validate vehicle type | Valid / Invalid Vehicle |
| User Category (F/S/G) | Validate user category | Valid / Invalid Category |
| Parking Permit (Y/N) | Validate permit status | Valid / Invalid Permit |
| Emergency Vehicle (Y/N) | Check emergency status when permit is invalid | Emergency / Non-Emergency |
| Vehicle Type + User Category + Permit | Determine parking eligibility and preferred zone | Accepted / Rejected |
| Zone Capacity | Check whether sufficient parking space is available | Assigned Zone / Rejection |
| Vehicle Type | Determine required parking spaces (Van = 2, Car/Bike = 1) | Updated Zone Occupancy |
| Accepted Vehicle | Update vehicle counters | Cars / Bikes / Vans Parked |
| Rejected Vehicle | Increment rejected vehicle counter | Total Rejected Vehicles |
| Zone Occupancy | Calculate remaining capacity | Remaining Capacity of Each Zone |
| Zone Occupancy | Compare occupancy of all zones | Zone with Highest Occupancy |
| Zone Capacities | Check whether all zones are full | Campus Full / Not Full |

<br><br>

### **PAC CHART**
| Problem | Analysis and Solution |
|---|---|
| Process vehicles | Use a loop to process each vehicle one at a time |
| Validate vehicle type | Accept only C (Car), B (Bike), or V (Van) |
| Validate user category | Accept only F (Faculty), S (Student), or G (Visitor) |
| Validate permit | Accept only Y or N |
| Handle invalid input | Reject invalid information and ask for the value again |
| Faculty with valid permit | Assign to Zone A if sufficient space is available |
| Student with valid permit | Assign to Zone B if sufficient space is available |
| Visitor with valid permit | Assign to Zone C if sufficient space is available |
| Faculty with van | Allow Zone A only if sufficient space is available |
| Student with van | Redirect to Zone C if space is available; otherwise reject |
| Student bike | Allow Zone B with a valid permit |
| Faculty bike | Allow Zone A with a valid permit |
| Visitor car/bike | Allow Zone C with a valid permit |
| Visitor van | Allow Zone C only if at least 2 spaces are available |
| Invalid permit | Reject vehicle unless it is an emergency vehicle |
| Emergency vehicle | Allow entry regardless of permit and assign according to user category |
| Parking space calculation | Car/Bike uses 1 space; Van uses 2 spaces |
| Zone capacity | Check available capacity before assigning a vehicle |
| Alternative zone | Apply alternative-zone rules when the preferred zone has insufficient space |
| Accepted vehicle | Display assigned zone and remaining capacity |
| Rejected vehicle | Display reason for rejection |
| Vehicle counters | Maintain counters for successfully parked cars, bikes, and vans |
| Rejected counter | Maintain a counter for rejected vehicles |
| Final summary | Display total processed, accepted, rejected, cars, bikes, and vans |
| Zone summary | Display final occupancy and remaining capacity of Zones A, B, and C |
| Highest occupancy | Compare zone occupancies and display the zone with highest occupancy |
| Campus capacity | Check whether the entire parking facility is full |

<br><br>
# PART B - QUESTION 6
## *Smart EV Charging and Parking Management System*

<br><br>
## **IPO CHART**
| Input | Process | Output |
|---|---|---|
| Vehicle Type (E/H) | Check whether the vehicle qualifies for EV charging | Charging Eligibility |
| Current Battery Level (SOC %) | `Required = Required Level - SOC` | Required Charging |
| Required Charging Level (%) | Compare required level with current battery level | Charging Required / Not Required |
| Parking Duration (hours) | Determine parking charge based on duration | Parking Cost |
| Current Time | Determine peak or off-peak status | Peak / Off-Peak |
| Membership (Y/N) | Apply applicable charging and parking discounts | Discount |
| Disabled Priority (Y/N) | Determine priority and parking eligibility | Charging Priority / Parking Discount |
| Charging Station Availability (Y/N) | Check whether charging is available | Charging Available / Unavailable |
| Battery Level + Required Level | Determine charging priority | Emergency / Priority / Normal |
| Required Charging + Charging Rate | Calculate charging cost | Charging Cost |
| Parking Cost + Discounts | Calculate final parking cost | Discounted Parking Cost |
| Charging Cost + Parking Cost | Calculate total payable amount | Final Payable Amount |
| Parking Duration | Check if duration > 8 hours | Long-Stay Warning / Standard Duration |

<br><br>

## **PAC CHART**

| Problem | Analysis  and Solution |
|---|---|
| Check charging station | If unavailable, hybrid gets "Charging unavailable – Parking only"; otherwise display "No charging slot available" for other vehicles |
| Check vehicle eligibility | Electric vehicles can charge, hybrids can charge only if battery level is below 40% |
| Calculate required charging | `Required Charging = Required Level - Current Battery Level` |
| Check charging requirement | If required level <= current battery level, display "No charging required" |
| Emergency Charging Priority | If battery <= 15% AND required level >= 80%, assign "Emergency Charging Priority" |
| Priority Charging | If not emergency AND disabled priority = Y, OR membership = Y AND battery <= 30%, assign "Priority Charging" |
| Normal Charging | If neither priority condition is satisfied, assign "Normal Charging" |
| Determine time period | Before 5 PM or after 10 PM = Off-Peak; 5 PM–10 PM = Peak |
| Off-Peak charging | Charge Rs. 35 per charging unit; member receives 20% discount |
| Peak charging | Charge Rs. 50, apply 10% discount |
| Emergency charging discount | No membership discount for Emergency Charging Priority |
| Calculate parking cost | 2 hours = Rs. 200, 5 hours = Rs. 400, else hours = Rs. 700 |
| Parking discount | Member receives 20% parking discount |
| Disabled priority parking | Disabled-person priority customers receive free parking |
| Long-stay check | If parking duration > 8 hours, display long-stay warning |
| Final calculation | Add charging cost and parking cost after applicable discounts |
| Display results | Display vehicle type, battery %, required charging %, priority, peak/off-peak status, costs, discount, final amount, and warning message |





