
/*
    Problem Statement-
    Periodic Table
    A Periodic Table Project allows you to search the elements both by their periodic name and their atomic number.
    To search for the element by periodic name you have type “Element Name”- ”Atomic Number”.
    Also, as mentioned you can search the elements by their atomic number.
    After you search the element it will show you the results by displaying their details
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int session_mapper();
int search_atomic_number();
int search_atomic_name();
void display_element_profile(int element_index);

char element_names[118][20]={"Hydrogen","Helium","Lithium","Beryllium","Boron","Carbon","Nitrogen","Oxygen","Flourine","Neon",
					"Sodium", "Magnesium", "Aluminium", "Silicon", "Phosphorus", "Sulphur", "Chlorine", "Argon",
					"Potassium","Calcium","Scandium","Titanium","Vanadium","Chromium","Manganese","Iron","Cobalt","Nickel","Copper","Zinc",
					"Gallium","Germanium","Arsenic","Selenium","Bromine","Krypton",
					"Rubidium","Strontium","Yttrium","Zirconium","Niobium","Molybdenum","Technetium","Ruthenium","Rhodium","Palladium","Silver","Cadmium",
					"Indium","Tin","Antimony","Tellurium","Iodine","Xenon",
					"Cesium","Barium","Lanthanum","Cerium","Praseodymium","Neodymium","Promethium","Samarium","Europium","Gadolinium","Terbium","Dysprosium",
					"Holmium","Erbium","Thulium","Ytterbium","Lutetium",
					"Hafnium","Tantalum","Tungsten","Rhenium","Osmium","Iridium","Platinum","Gold","Mercury","Thallium","Lead","Bismuth","Polonium","Astatine","Radon",
					"Francium","Radium","Actinium","Thorium","Protactinium","Uranium","Neptunium","Plutonium","Americium","Curium","Berkelium",
					"Californium","Einsteinium","Fermium","Mendelevium","Nobelium","Lawrencium",
					"Rutherfordium","Dubnium","Seaborgium","Bohrium","Hassium","Meitnerium","Darmstadtium","Roentgenium","Copernicium", "Nihonium", "Flerovium","Moscovium", "Livermonium", "Tennessine", "Oganesson"};


char symbol[118][5]={"H","He","Li","Be","B","C","N","O","F","Ne",
                     "Na","Mg","Al","Si","P","S","Cl","Ar",
					 "K","Ca","Sc","Ti","V","Cr","Mn","Fe","Co","Ni","Cu","Zn","Ga","Ge","As","Se","Br","Kr",
					 "Rb","Sr","Y","Zr","Nb","Mo","Tc","Ru","Rh","Pd","Ag","Cd","In","Sn","Sb","Te","I","Xe",
					 "Cs","Ba","La","Ce","Pr","Nd","Pm","Sm","Eu","Gd","Tb","Dy","Ho","Er","Tm","Yb","Lu",
					 "Hf","Ta","W","Re","Os","Ir","Pt","Au","Hg","Tl","Pb","Bi","Po","At","Rn",
                     "Fr","Ra","Ac","Th","Pa","U","Np","Pu","Am","Cm","Bk","Cf","Es","Fm",",Md","No","Lr",
					"Rf","Db","Sg","Bh","Hs","Mt","Ds","Rg","Cn","Nh","Fl","Mc","Lv","Ts","Og"};


double weight[118]={1.00,4.00,6.94,9.01,10.81,12.01,14.00,16.00,20.00,20.18,23.00,24.31,26.99,28.08,30.97,32.06,35.45,39.09,40.07,44.95,47.86,50.94,
					51.99,54.93,55.84,58.69,58.93,63.54,65.39,69.7,72.64,74.92,78.96,79.90,83.80,85.46,87.62,88.90,91.22,92.90,95.94,98.00,101.07,
					102.90,106.42,107.86,118.41,114.81,118.71,121.76,127.6,126.90,131.29,13.90,137.32,138.90,140.11,140.90,144.24,145.00,
					150.36,151.96,157.25,158.92,162.50,164.93,167.5,168.93,173.04,174.96,178.49,180.94,183.84,186.20,190.23,192.21,195.07,196.97,
					200.59,204.38,207.20,208.98,209.00,210.00,222.00,223.00,226.00,227.00,231.03,232.03,237.00,238.03,243,244,247,247,251,252,257,258,
					259,261,262,264,266,268,272,277,276,281,280,285,286,289,290,293,293.1,294};



int main() {

    int i=999, choice;
	do
	{
		choice = session_mapper();

		switch (choice) {
			case 1: i = search_atomic_number();
					break;
			case 2: i= search_atomic_name();
					break;
			case 3: return (0);
			default: system("cls");
					 printf("\n\n\t\t\t\tWrong Choice!\n");
		}
		if (i <= 0) {
			system("cls");
			printf("\t\t\t\t\t\tOops ! \n\t\t\t\t\tNo Such element present !\n");
		}
		else if (i==999)
			continue;
		else {
            display_element_profile(i);
		}
		i=999;
	}
	while (choice != 3);
	return (0);

}

int session_mapper() {

    /*
        Displays the main interface and accepts input from stdin as choice.
    */

    int choice;


	printf("\n\n Enter the corresponding number : \n\n");

	printf("1. Search by ATOMIC NUMBER\n");
	printf("2. Search by ATOMIC NAME\n");
	printf("3. QUIT\n");

	printf("\nEnter Your Choice : ");
	scanf("%d",&choice);

	return choice;
}

int search_atomic_number() {

    /*
        Accepts input from stdin and checks if the atomic number exists.
        Returns the atomic number if it exists and returns -1 if it does not.
    */

    int z_atomic_number;
	printf("\nEnter the Atomic Number : ");
	scanf("%d",  &z_atomic_number);
	z_atomic_number--;
    /*
        A decrement is used to decrease the integer value of z_atomic_number.
        The value will later on be used to get the name and properties of the element
        which has the value of z_atomic_number at runtime.
    */

	if (z_atomic_number >0 && z_atomic_number < 118) {
		return z_atomic_number;
    }
	else{
        return -1;
    }

}

int search_atomic_name() {

    /*
        Accepts input from stdin and checks if input String in the element_names array.
        If element exists, the index of the element is assigned to the variable element.
        Function returns the value of element.
    */

    char search_queryname[20];
    int search_flag=0;
    int element;
    int z_atomic_number;

	printf("\nEnter the 'Element Name'- 'Atomic Number' : ");
	scanf("%s - %d", search_queryname, &z_atomic_number);

	for (int i=0; i<118; i++) {
		if (strcmp(search_queryname, element_names[i]) == 0) {
            element = i;
		    search_flag = 1;
			break;
		}
	}

	if (search_flag == 1) {
		return element;
    }
    else {
        return -1;
    }

}

void display_element_profile(int element_index) {

    /*
        Displays the property and other useful information of an element based on its atomic number.
    */

	int atomic_number = element_index + 1;
	if (atomic_number==1 || atomic_number==3 || atomic_number==4 || atomic_number==11 || atomic_number==12 || atomic_number==19 || atomic_number==20 || atomic_number==37 || atomic_number==38 || atomic_number==55 || atomic_number==56 || atomic_number==87 || atomic_number==88) {

        printf("\n\t\t\t\t\t HERE'S YOUR SEARCH RESULT\n\n");
        printf("\n\t\t\t\t\tAtomic Number     : %d\n", (atomic_number));
        printf("\t\t\t\t\tAtomic Symbol     : %s\n", symbol[element_index]);
        printf("\t\t\t\t\tAtomic Name       : %s\n", element_names[element_index]);
        printf("\t\t\t\t\tAtomic Weight     : %.2f\n", weight[element_index]);
        printf("\t\t\t\t\tProperty : Element is in the S BLOCK and It is a METAL");

    }
	else if(atomic_number==2 || (atomic_number>=5 && atomic_number<=10) || (atomic_number>=13 && atomic_number<=18) || (atomic_number>=31 && atomic_number<=36) || (atomic_number>=49 && atomic_number<=54) || (atomic_number>=81 && atomic_number<=86)) {

		printf("\n\t\t\t\t\t HERE'S YOUR SEARCH RESULT\n\n");
        printf("\n\t\t\t\t\tAtomic Number     : %d\n", (atomic_number));
        printf("\t\t\t\t\tAtomic Symbol     : %s\n", symbol[element_index]);
        printf("\t\t\t\t\tAtomic Name       : %s\n", element_names[element_index]);
        printf("\t\t\t\t\tAtomic Weight     : %.2f\n", weight[element_index]);
        printf("\t\t\t\t\tProperty : Element is in the P BLOCK and It is a NON-METAL");
    }
	else if((atomic_number>=21 && atomic_number<=30) || (atomic_number>=39 && atomic_number<=48) || (atomic_number>=72 && atomic_number<=80) || (atomic_number>=104 && atomic_number<=118)) {
		printf("\n\t\t\t\t\t HERE'S YOUR SEARCH RESULT\n\n");
        printf("\n\t\t\t\t\tAtomic Number     : %d\n", (atomic_number));
        printf("\t\t\t\t\tAtomic Symbol     : %s\n", symbol[element_index]);
        printf("\t\t\t\t\tAtomic Name       : %s\n", element_names[element_index]);
        printf("\t\t\t\t\tAtomic Weight     : %.2f\n", weight[element_index]);
        printf("\t\t\t\t\tProperty : Element is in the D BLOCK and It is a TRANSITION METAL");
    }
	else {
        printf("\n\t\t\t\t\t HERE'S YOUR SEARCH RESULT\n\n");
        printf("\n\t\t\t\t\tAtomic Number     : %d\n", (atomic_number));
        printf("\t\t\t\t\tAtomic Symbol     : %s\n", symbol[element_index]);
        printf("\t\t\t\t\tAtomic Name       : %s\n", element_names[element_index]);
        printf("\t\t\t\t\tAtomic Weight     : %.2f\n", weight[element_index]);
        printf("\t\t\t\t\tProperty : Element is in the F BLOCK and It is a INNER TRANSITION METAL");
    }

}

