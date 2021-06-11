//Implementation of the Essay class
#include "Essay.h"

Essay::Essay()
	: GradedActivity(),
	grammarScore(0),
	spellingScore(0),
	correctLengthScore(0),
	contentScore(0)
{ }

void Essay::GrammarPoints(int points)
{
	if (points > 0 && points + grammarScore <= 30)
	{
		grammarScore += points;
		score += grammarScore;
	}
}

void Essay::SpellingPoints(int points)
{
	if (points > 0 && points + spellingScore <= 20)
	{
		spellingScore += points;
		score += spellingScore;
	}
}

void Essay::CorrectLengthPoints(int points)
{
	if (points > 0 && points + correctLengthScore <= 20)
	{
		correctLengthScore += points;
		score += correctLengthScore;
	}
}

void Essay::ContentPoints(int points)
{
	if (points > 0 && points + contentScore <= 30)
	{
		contentScore += points;
		score += contentScore;
	}
}
