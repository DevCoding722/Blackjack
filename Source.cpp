
#include <iostream>
#include <stdlib.h>
int Choice;
int HitFunction(int PlayerHitHand);
int SplitHitFunction(int SplitHitHand1);
int SplitHit2Function(int SplitHitHand2);
int SplitStay(int DealerHand);
int StayFunction(int DealerStayHand);
using std::cout;
using std::cin;
using std::endl;
int main()
{
	srand(static_cast<int>(time(NULL)));
	bool Play = true;
	bool Splitplay = false;
	int DealerCard1 = rand() % 11 + 1;
	int DealerCard2 = rand() % 11 + 1;
	int PlayerCard1 = rand() % 11 + 1;
	int PlayerCard2 = rand() % 11 + 1;
	int PlayerCard3 = rand() % 11 + 1;
	int PlayerCard4 = rand() % 11 + 1;
	int DealerHand = DealerCard1 + DealerCard2;
	int PlayerHand = PlayerCard1 + PlayerCard2;
	if (PlayerCard1 && PlayerCard2 == 11)
	{
		PlayerCard1 -= 1;
		cout << "Playercard1 is now equal to: " << PlayerCard1 << endl;
	}
	if (DealerCard1 && DealerCard2 == 11)
	{
		DealerCard1 -= 1;
		cout << "Dealercard1 is now equal to: " << DealerCard1 << endl;
	}
	if (DealerHand == 21)
	{
		cout << "Dealer has a natural blackjack you lose!" << endl;
		Play = false;
		Splitplay = false;
		return 0;
	}
	if (PlayerCard1 == PlayerCard2 || Splitplay == true)
	{

		char YesNo;
		cout << "Your first card: " << PlayerCard1 << " " << "Your second card: " << PlayerCard2 << endl;
		cout << "Would you like to split?" << endl;
		cout << "Y/N" << endl;
		cin >> YesNo;
		int PlayerHandSplit1 = PlayerCard1 + PlayerCard3;
		int PlayerHandSplit2 = PlayerCard2 + PlayerCard4;
		if (YesNo == 'Y' || YesNo == 'y')
		{
			do
			{
				bool Hit1 = true;
				bool Hit = true;
				Splitplay = true;
				cout << "Spliting..." << endl;
				cout << "Dealer:" << endl;
				cout << DealerHand << endl;
				cout << "Playercard 1: " << PlayerCard1 << " " << "Playercard 2: " << PlayerCard2 <<
					" " << "Playercard 3: " << PlayerCard3 << " " << "Playercard 4: " << PlayerCard4 << endl;
				cout << "Playerhand 1: " << PlayerHandSplit1 << " " << " Playerhand 2: " << PlayerHandSplit2 << endl;
				cout << "Would you like to hit?" << endl;
				cout << "1)Hit" << endl;
				cout << "2)Stay" << endl;
				cin >> Choice;
				switch (Choice)
				{
				case 1:
					while (Hit1)
					{
						PlayerHandSplit1 += SplitHitFunction(PlayerHandSplit1);
						cout << "Dealer:" << endl;
						cout << DealerHand << endl;
						cout << "Playercard 1: " << PlayerCard1 << " " << "Playercard 2: " << PlayerCard2 << " "
							<< "Playercard 3: " << PlayerCard3 << " " << "Playercard 4: " << PlayerCard4 << endl;
						cout << "Playerhand 1: " << PlayerHandSplit1 << " " << " Playerhand 2: " << PlayerHandSplit2 << endl;
						if (PlayerHandSplit1 > 21 || PlayerHandSplit2 > 21)
						{
							cout << "You busted! You lose!" << endl;
							cout << "Dealer:" << endl;
							cout << DealerHand << endl;
							cout << "Playercard 1: " << PlayerCard1 << " " << "Playercard 2: " << PlayerCard2 << " "
								<< "Playercard 3: " << PlayerCard3 << " " << "Playercard 4: " << PlayerCard4 << endl;
							cout << "Playerhand 1: " << PlayerHandSplit1 << " " << " Playerhand 2: " << PlayerHandSplit2 << endl;
							Splitplay = false;
							Hit1 = false;
						}
						char YesNo;
						cout << "Would you like to hit again?" << endl;
						cout << "Y/N?" << endl;
						cin >> YesNo;
						if (YesNo == 'Y' || YesNo == 'y')
						{

						}
						else
						{
							Hit1 = false;
						}
					}
					break;
				case 2:
					while (DealerHand <= 16)
					{
						DealerHand += SplitStay(PlayerHandSplit1);
						cout << "Dealer:" << endl;
						cout << DealerHand << endl;
						cout << "Player:" << endl;
						cout << "Playercard 1: " << PlayerCard1 << " " << "Playercard 2: " << PlayerCard2
							<< " " << "Playercard 3: " << PlayerCard3 << " " << "Playercard 4: " << PlayerCard4 << endl;
						cout << "Playerhand 1: " << PlayerHandSplit1 << " " << " Playerhand 2: " << PlayerHandSplit2 << endl;
						Hit1 = false;
						Splitplay = false;
						Play = false;
						if (DealerHand > 21)
						{
							cout << "Dealer busted! You win!" << endl;
							cout << "Dealer:" << endl;
							cout << DealerHand << endl;
							cout << "Playercard 1: " << PlayerCard1 << " " << "Playercard 2: " << PlayerCard2 << " "
								<< "Playercard 3: " << PlayerCard3 << " " << "Playercard 4: " << PlayerCard4 << endl;
							cout << "Playerhand 1: " << PlayerHandSplit1 << " " << " Playerhand 2: " << PlayerHandSplit2 << endl;
							Splitplay = false;
							Hit = false;
							Play = false;
						}
					}

					break;
				default:
					break;
				}
				if (Play == true)
				{
					cout << "Spliting..." << endl;
					cout << "Dealer:" << endl;
					cout << DealerHand << endl;
					cout << "Playercard 1: " << PlayerCard1 << " " << "Playercard 2: " << PlayerCard2 <<
						" " << "Playercard 3: " << PlayerCard3 << " " << "Playercard 4: " << PlayerCard4 << endl;
					cout << "Playerhand 1: " << PlayerHandSplit1 << " " << " Playerhand 2: " << PlayerHandSplit2 << endl;
					cout << "For second hand hit?" << endl;
					cout << "Would you like to hit?" << endl;
					cout << "1)Hit" << endl;
					cout << "2)Stay" << endl;
					cin >> Choice;
					switch (Choice)
					{
					case 1:
						while (Hit)
						{
							PlayerHandSplit2 += SplitHit2Function(PlayerHandSplit2);
							cout << "Dealer:" << endl;
							cout << DealerHand << endl;
							cout << "Playercard 1: " << PlayerCard1 << " " << "Playercard 2: " << PlayerCard2 << " "
								<< "Playercard 3: " << PlayerCard3 << " " << "Playercard 4: " << PlayerCard4 << endl;
							cout << "Playerhand 1: " << PlayerHandSplit1 << " " << " Playerhand 2: " << PlayerHandSplit2 << endl;
							if (PlayerHandSplit1 > 21 || PlayerHandSplit2 > 21)
							{
								cout << "You busted! You lose!" << endl;
								cout << "Dealer:" << endl;
								cout << DealerHand << endl;
								cout << "Playercard 1: " << PlayerCard1 << " " << "Playercard 2: " << PlayerCard2 << " "
									<< "Playercard 3: " << PlayerCard3 << " " << "Playercard 4: " << PlayerCard4 << endl;
								cout << "Playerhand 1: " << PlayerHandSplit1 << " " << " Playerhand 2: " << PlayerHandSplit2 << endl;
								Splitplay = false;
								Hit = false;
							}
							char YesNo;
							cout << "Would you like to hit again?" << endl;
							cout << "Y/N?" << endl;
							cin >> YesNo;
							if (YesNo == 'Y' || YesNo == 'y')
							{

							}
							else
							{
								Hit = false;
								while (DealerHand <= 16)
								{
									DealerHand += SplitStay(PlayerHandSplit1);
									cout << "Dealer:" << endl;
									cout << DealerHand << endl;
									cout << "Player:" << endl;
									cout << "Playercard 1: " << PlayerCard1 << " " << "Playercard 2: " << PlayerCard2
										<< " " << "Playercard 3: " << PlayerCard3 << " " << "Playercard 4: " << PlayerCard4 << endl;
									cout << "Playerhand 1: " << PlayerHandSplit1 << " " << " Playerhand 2: " << PlayerHandSplit2 << endl;
									Hit = false;
									if (DealerHand > 21)
									{
										cout << "Dealer busted! You win!" << endl;
										cout << "Dealer:" << endl;
										cout << DealerHand << endl;
										cout << "Playercard 1: " << PlayerCard1 << " " << "Playercard 2: " << PlayerCard2 << " "
											<< "Playercard 3: " << PlayerCard3 << " " << "Playercard 4: " << PlayerCard4 << endl;
										cout << "Playerhand 1: " << PlayerHandSplit1 << " " << " Playerhand 2: " << PlayerHandSplit2 << endl;
										Splitplay = false;
										Hit = false;
										Play = false;
									}
								}
								Splitplay = false;
								Play = false;
							}
						}
						break;
					case 2:
						while (DealerHand <= 16)
						{
							DealerHand += SplitStay(PlayerHandSplit1);
							cout << "Dealer:" << endl;
							cout << DealerHand << endl;
							cout << "Player:" << endl;
							cout << "Playercard 1: " << PlayerCard1 << " " << "Playercard 2: " << PlayerCard2
								<< " " << "Playercard 3: " << PlayerCard3 << " " << "Playercard 4: " << PlayerCard4 << endl;
							cout << "Playerhand 1: " << PlayerHandSplit1 << " " << " Playerhand 2: " << PlayerHandSplit2 << endl;
							Hit = false;
							if (DealerHand > 21)
							{
								cout << "Dealer busted! You win!" << endl;
								cout << "Dealer:" << endl;
								cout << DealerHand << endl;
								cout << "Playercard 1: " << PlayerCard1 << " " << "Playercard 2: " << PlayerCard2 << " "
									<< "Playercard 3: " << PlayerCard3 << " " << "Playercard 4: " << PlayerCard4 << endl;
								cout << "Playerhand 1: " << PlayerHandSplit1 << " " << " Playerhand 2: " << PlayerHandSplit2 << endl;
								Splitplay = false;
								Hit = false;
								Play = false;
							}
						}
						Splitplay = false;
						Play = false;
						break;
					default:
						break;
					}
				}
			} while (Splitplay == true);
		}
		else
		{
			Splitplay = false;
			Play = true;
		}
		if (!Play && PlayerHandSplit1 > 21 || PlayerHandSplit2 > 21)
		{
			cout << "You busted! You lose!" << endl;
			cout << "Dealer:" << endl;
			cout << DealerHand << endl;
			cout << "Player:" << endl;
			cout << "Playercard 1: " << PlayerCard1 << " " << "Playercard 2: " << PlayerCard2 << " "
				<< "Playercard 3: " << PlayerCard3 << " " << "Playercard 4: " << PlayerCard4 << endl;
			cout << "Playerhand 1: " << PlayerHandSplit1 << " " << " Playerhand 2: " << PlayerHandSplit2 << endl;
			Play = false;
			return 0;
		}
		else if (!Play && PlayerHandSplit1 > DealerHand && PlayerHandSplit1 <= 21)
		{
			cout << "YOU WIN!!" << endl;
			cout << "The Dealer had less then you. You win!!" << endl;
			cout << "Dealer:" << endl;
			cout << DealerHand << endl;
			cout << "Player:" << endl;
			cout << PlayerHandSplit1 << endl;
			Play = false;
			return 0;
		}
		else if (!Play && PlayerHandSplit2 > DealerHand && PlayerHandSplit2 <= 21)
		{
			cout << "YOU WIN!!" << endl;
			cout << "The Dealer had less then you. You win!!" << endl;
			cout << "Dealer:" << endl;
			cout << DealerHand << endl;
			cout << "Player:" << endl;
			cout << PlayerHandSplit2 << endl;
			Play = false;
			return 0;
		}
		else if (!Play && PlayerHandSplit1 < DealerHand && DealerHand <= 21)
		{
			cout << "YOU LOSE!!" << endl;
			cout << "The Dealer had more than you. You lose!!" << endl;
			cout << "Dealer:" << endl;
			cout << DealerHand << endl;
			cout << "Player:" << endl;
			cout << PlayerHandSplit1 << endl;
			Play = false;
			return 0;
		}
		else if (!Play && PlayerHandSplit2 < DealerHand && DealerHand <= 21)
		{
			cout << "YOU LOSE!!" << endl;
			cout << "The Dealer had more than you. You lose!!" << endl;
			cout << "Dealer:" << endl;
			cout << DealerHand << endl;
			cout << "Player:" << endl;
			cout << PlayerHandSplit2 << endl;
			Play = false;
			return 0;

		}
		else if (!Play && PlayerHandSplit1 == DealerHand || PlayerHandSplit2 == DealerHand)
		{
			cout << "Push" << endl;
		}
	}
	if (Splitplay == false && Play == true)
	{
		do
		{
			cout << "Dealer must stand on all 17s..." << endl;
			cout << "Welcome to Blackjack!" << endl;
			cout << "Dealer:" << endl;
			cout << DealerHand << endl;
			cout << "Player:" << endl;
			cout << PlayerHand << endl;
			cout << "Would you like to hit?" << endl;
			cout << "1)Hit" << endl;
			cout << "2)Stay" << endl;
			cin >> Choice;
			switch (Choice)
			{
			case 1:
				PlayerHand += HitFunction(PlayerHand);
				cout << "Dealer:" << endl;
				cout << DealerHand << endl;
				cout << "Player:" << endl;
				cout << PlayerHand << endl;
				if (PlayerHand > 21)
				{
					cout << "You busted! You lose!" << endl;
					cout << "Dealer:" << endl;
					cout << DealerHand << endl;
					cout << "Player:" << endl;
					cout << PlayerHand << endl;
					Play = false;
				}
				break;
			case 2:
				while (DealerHand <= 16)
				{
					DealerHand += StayFunction(DealerHand);
					cout << "Dealer:" << endl;
					cout << DealerHand << endl;
					cout << "Player:" << endl;
					cout << PlayerHand << endl;
				}
				Play = false;
			default:
				break;
			}
		} while (Play);
		if (PlayerHand > DealerHand && PlayerHand <= 21)
		{
			cout << "YOU WIN!!" << endl;
			cout << "The Dealer had less then you. You win!!" << endl;
			cout << "Dealer:" << endl;
			cout << DealerHand << endl;
			cout << "Player:" << endl;
			cout << PlayerHand << endl;
			Play = false;
		}
		else if (PlayerHand < DealerHand && DealerHand <= 21)
		{
			cout << "YOU LOSE!!" << endl;
			cout << "The Dealer had more than you. You lose!!" << endl;
			cout << "Dealer:" << endl;
			cout << DealerHand << endl;
			cout << "Player:" << endl;
			cout << PlayerHand << endl;
			Play = false;
		}
		else if (DealerHand > 21)
		{
			cout << "The Dealer busted you win!!" << endl;
			cout << "Dealer:" << endl;
			cout << DealerHand << endl;
			cout << "Player:" << endl;
			cout << PlayerHand << endl;
			Play = false;
		}
		else if (PlayerHand > 21)
		{
			cout << "You busted! You lose!" << endl;
			cout << "Dealer:" << endl;
			cout << DealerHand << endl;
			cout << "Player:" << endl;
			cout << PlayerHand << endl;
			Play = false;
		}
		else if (PlayerHand == DealerHand)
		{
			cout << "Push" << endl;
			Play = false;
		}
	}
}

int HitFunction(int PlayerHitHand)
{
	int Hit1 = rand() % 11 + 1;
	if (PlayerHitHand >= 11 && Hit1 == 11)
	{
		Hit1 = 1;
		cout << "Hit is now equal to: " << Hit1 << endl;
		return Hit1;
	}
	else
	{
		cout << "Hit has no modifier is now equal to: " << Hit1 << endl;
		return Hit1;
	}
}
int SplitHitFunction(int SplitHitHand1)
{
	int splitHit1 = rand() % 11 + 1;

	if (SplitHitHand1 >= 11 && splitHit1 == 11)
	{
		splitHit1 = 1;
		cout << "Hit1 is now equal to:  " << splitHit1 << endl;
		return splitHit1;
	}
	else
	{
		cout << "Hit1 from SplitHit1:  " << splitHit1 << endl;
		return splitHit1;
	}
}
int SplitHit2Function(int SplitHitHand2)
{
	int splitHit2 = rand() % 11 + 1;
	if (SplitHitHand2 >= 11 && splitHit2 == 11)
	{
		splitHit2 = 1;
		cout << "Hit1 is now equal to: " << splitHit2 << endl;
		return splitHit2;
	}
	else
	{
		cout << "Hit2 from SplitHit2:  " << splitHit2 << endl;
		return splitHit2;
	}
}
int SplitStay(int DealerHand)
{
	int splitStay = rand() % 11 + 1;
	if (DealerHand >= 11 && splitStay == 11)
	{
		splitStay = 1;
		cout << "Dealer hit is now equal to: " << splitStay << endl;
		return splitStay;
	}
	else
	{
		cout << "Dealer hit is now equal to: " << splitStay << endl;
		return splitStay;
	}
}
int StayFunction(int DealerStayHand)
{
	int Stay = rand() % 11 + 1;
	if (DealerStayHand >= 11 && Stay == 11)
	{
		Stay = 1;
		cout << "Hit is now equal to: " << Stay << endl;
		return Stay;
	}
	else
	{
		cout << "Dealer's cards: " << Stay << endl;
		return Stay;
	}
}