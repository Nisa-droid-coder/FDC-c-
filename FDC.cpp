#include <iostream>
#include <string>

using namespace std;

// Function to display the quiz and return the score
int takeQuiz(const string questions[][5], const string options[][5][4], const int answers[], int quizNumber) {
    int score = 0;
    int userAnswer;

    cout << "\n--- Quiz " << quizNumber << " ---\n";
    for (int i = 0; i < 5; i++) {
        cout << "Q" << (i + 1) << ": " << questions[quizNumber - 1][i] << endl;
        for (int j = 0; j < 4; j++) {
            cout << "  " << char('A' + j) << ": " << options[quizNumber - 1][i][j] << endl;
        }
        cout << "Your answer (A/B/C/D): ";
        char answer;
        cin >> answer;
        userAnswer = toupper(answer) - 'A'; // Convert char to index (0-3)

        if (userAnswer == answers[i]) {
            score++;
        }
    }
    return score;
}

// Function to display correct answers
void displayCorrectAnswers(const string questions[][5], const string options[][5][4], const int answers[], int quizNumber) {
    cout << "\n--- Correct Answers for Quiz " << quizNumber << " ---\n";
    for (int i = 0; i < 5; i++) {
        cout << "Q" << (i + 1) << ": " << questions[quizNumber - 1][i] << endl;
        cout << "Correct Answer: " << char('A' + answers[i]) << " - " << options[quizNumber - 1][i][answers[i]] << endl;
    }
}

int main() {
    // Quiz questions, options, and correct answers
    const string questions[3][5] = {
        {
            "What does 'phishing' refer to in cybersecurity?",
            "Which of the following is a strong password?",
            "What is the purpose of a firewall?",
            "What is malware?",
            "What does 'two-factor authentication' provide?"
        },
        {
            "What is digital literacy?",
            "Which of the following is an example of digital collaboration?",
            "What is the primary purpose of a digital portfolio?",
            "What does 'cloud computing' allow users to do?",
            "What is a key skill for digital citizenship?"
        },
        {
            "What is the primary goal of digital marketing?",
            "Which platform is commonly used for social media marketing?",
            "What does SEO stand for?",
            "What is a common metric for measuring online engagement?",
            "What is the purpose of content marketing?"
        }
    };

    const string options[3][5][4] = {
        {
            {"A) A type of fishing", "B) A method of stealing information", "C) A computer virus", "D) A security protocol"},
            {"A) 123456", "B) password", "C) P@ssw0rd!", "D) qwerty"},
            {"A) To block unwanted traffic", "B) To speed up the internet", "C) To store data", "D) To create backups"},
            {"A) A type of software", "B) A hardware component", "C) A network protocol", "D) A type of encryption"},
            {"A) Increased security", "B) Faster login", "C) Simpler passwords", "D) Automatic updates"}
        },
        {
            {"A) The ability to use technology effectively", "B) The ability to read digital content", "C) The ability to write code", "D) The ability to create websites"},
            {"A) Working on a shared document online", "B) Sending emails", "C) Using a word processor", "D) Browsing the internet"},
            {"A) To showcase skills and achievements", "B) To store files", "C) To create a resume", "D) To share photos"},
            {"A) Store data on local devices", "B) Access data over the internet", "C) Create software applications", "D) Improve internet speed"},
            {"A) Understanding online etiquette", "B) Knowing how to code", "C) Creating websites", "D) Using social media"}
        },
        {
            {"A) To sell products", "B) To increase brand awareness", "C) To create websites", "D) To improve customer service"},
            {"A) LinkedIn", "B) Google", "C) Amazon", "D) eBay"},
            {"A) Search Engine Optimization", "B) Social Engagement Online", "C) Secure Email Operations", "D) Standardized Electronic Output"},
            {"A) Click-through rate", "B) Page views", "C) Likes", "D) All of the above"},
            {"A) To entertain", "B) To inform and engage customers", "C) To sell products directly", "D) To create advertisements"}
        }
    };

    const int answers[3][5] = {
        {1, 2, 0, 0, 0}, // Correct answers for Quiz 1 (Cybersecurity)
        {0, 0, 0, 1, 0}, // Correct answers for Quiz 2 (Digital Competence)
        {1, 0, 0, 3, 1}  // Correct answers for Quiz 3 (Digital Marketing)
    };

    int quizChoice;
    cout << "Welcome to the Quiz Platform!" << endl;
    cout << "Please select a quiz to take (1-3): ";
    cin >> quizChoice;

    if (quizChoice < 1 || quizChoice > 3) {
        cout << "Invalid choice. Please select a quiz between 1 and 3." << endl;
        return 1;
    }

    int score = takeQuiz(questions, options, answers[quizChoice - 1], quizChoice);
    cout << "\nYour score: " << score << "/5" << endl;

    displayCorrectAnswers(questions, options, answers[quizChoice - 1], quizChoice);

    return 0;
}
