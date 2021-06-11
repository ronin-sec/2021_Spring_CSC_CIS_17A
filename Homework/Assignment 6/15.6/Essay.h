
#ifndef ESSAY_H
#define ESSAY_H

#include "GradedActivity.h"

class Essay : public GradedActivity
{
private:
	int grammarScore;
	int spellingScore;
	int correctLengthScore;
	int contentScore;

public:
	Essay();
	void GrammarPoints(int points);
	void SpellingPoints(int points);
	void CorrectLengthPoints(int points);
	void ContentPoints(int points);
};

#endif /* ESSAY_H */

