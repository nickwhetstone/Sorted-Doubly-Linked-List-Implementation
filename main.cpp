// Include
#include<iostream>

// Standard namespace
using namespace std;

// A node has its own data, a pointer to the previous node, and a pointer to the
// next node.
struct node {
	int data;
	node *prev;
	node *next;
};

// Function for inserting nodes.
node *insertNode(node *head, int data)
{
	node *tmp = head;
	node *other = nullptr;
	node *addnode = new node;
	addnode->data = data;
	addnode->next = nullptr;
	addnode->prev = nullptr;
	
	// If head isn't set already, this is the first node in the list.
	if (!head)
	{
		// Get out of here.
		return addnode;
	}

	while (tmp && (data>=(tmp->data)))
	{
		other = tmp;
		tmp = tmp->next;
	}
	
	if (tmp == nullptr)
	{
		other->next = addnode;
		addnode->prev = other;
		return head;
	}
	
	if(other == nullptr)
	{
		head->prev = addnode;
		addnode->next = head;
		return addnode;
	}
	other->next = addnode;
	addnode->prev = other;
	addnode->next = tmp;
	tmp->prev = addnode;
	return head;
}

// Main function. Cmd line arguments aren't necessary here, just left in to
// display knowledge of how to use them.
int main(int argc, char *argv[])
{
	// We'll use all of these at some point in the 6 cases
	int i;
	int option;
	int nodes;
	int newnode;
	int delnode;
	
	node *head = nullptr;
	node *tmp = nullptr;
	node *junk = nullptr;
	
	// An infinite loop
	while(1)
	{
		// Display the user's options
		cout
		<< "Please choose from one of the options below.\n"
		<< "1. Create a new doubly linked list\n"
		<< "2. Add number to list\n"
		<< "3. Delete a particular number from the list\n"
		<< "4. Print in ascending order\n"
		<< "5. Print in descending order\n"
		<< "6. Exit the program\n";
		if (!(cin >> option))
		{
			cout << "Hacker...\n";
			exit(1);
		}
		switch(option)
		{
			// Create a new list
			case 1:
			{
				cout << "How many nodes would you like to create?\n";
				if (!(cin >> nodes))
				{
					cout << "Hacker...\n";
					exit(1);
				}
				else
				{
					for (i = 0; i < nodes; i++)
						// insertNode returns a pointer to a node whose data is
						// a random number
						head = insertNode(head, (rand() % 5000));
					cout << nodes << "-element list created!\n";
				}
				break;
			}
			// Add a number to the list.
			case 2:
			{
				cout << "What number would you like to add to the list?\n";
				if (!(cin >> newnode))
				{
					cout << "Hacker...\n";
					exit(1);
				}
				else
				{
					head = insertNode(head, newnode);
					cout << newnode << " has been added to the list!\n";
				}
				break;
			}
			// Delete all instances of a number from the list.
			case 3:
			{
				cout << "What number would you like to delete from the list?\n";
				if (!(cin >> delnode))
				{
					cout << "Hacker...\n";
					exit(1);
				}
				tmp = head;
				while (tmp)
				{
					if (tmp->data == delnode)
					{
						// We're at the beginning.
						if (!(tmp->prev))
						{
							head = tmp->next;
						}
						// We're at the end.
						else if(!(tmp->next))
						{
							tmp->prev->next = nullptr;
						}
						// We're in the middle.
						else
						{
							tmp->prev->next = tmp->next;
							tmp->next->prev = tmp->prev;
							junk = tmp->next;
						}
						delete tmp;
						tmp = junk;
					}
					else
						tmp = tmp->next;
				}
				break;
			}
			// Print in ascending order
			case 4:
			{
				i = 0;
				cout << "List (ascending order)\n";
				tmp = head;
				while(tmp)
				{
					cout << i+1 << ": " << tmp->data << "\n";
					tmp = tmp->next;
					i++;
				}
				break;
			}
			// Print in descending order
			case 5:
			{
				i = 0;
				cout << "Reversed list (descending order)\n";
				while(head)
				{
					tmp = head;
					head = head->next;
				}
				while(tmp)
				{
					cout << i+1 << ": " << tmp->data << "\n";
					head = tmp;
					tmp = tmp->prev;
					i++;
				}
				break;
			}
			case 6:
			{
				// Delete the nodes
				while(head)
				{
					tmp = head;
					head = head->next;
					// Free the memory
					delete tmp;
				}
				// Good to go!
				cout << "Memory freed. Now exiting!\n";
				exit(0);
			}
			// If the user doesn't enter 1,2,3,4,5, or 6.
			default:
			{
				cout << "Invalid option\n";
				break;
			}
		}
	}
	return 0;
}