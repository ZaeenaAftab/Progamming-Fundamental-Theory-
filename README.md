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




