        // Save task to file
    void saveToFile(ofstream& txtOut) const {
        txtOut << name << endl;
        txtOut << description << endl;
        txtOut << dueDate << endl;
        txtOut << (completed ? "true" : "false") << endl;
    }

    // Load task from file
    void loadFromFile(ifstream& txtIn) {
        getline(txtIn, name);
        getline(txtIn, description);
        getline(txtIn, dueDate);
        txtIn >> completed;
        txtIn.ingore(); // Ignore newline character after reading completed
    }
    
    
    // Save task to txt
    void saveToFile(const string& filename) {
        ofstream outFile(filename);
        if (!outFile) {
            cerr << "Error opening file for writing!" << endl;
            return;
        }
        for (const auto& task : tasks) {
            task.saveToFile(outFile);
        }
        outFile.close();
        cout << "Tasks save to " << filename << endl;
    }

    // Load tasks from file
    void loadFromFile (const string& filename) {
        ifstream inFile(filename);
        if (!inFile) {
            cerr << "Error opening file for reading!" << endl;
            return;
        }
        tasks.clear();
        while (!inFile.eof()) {
            Task task("", "", "");
            task.loadFromFile(inFile);
            if (!task.getName().empty()) {
                tasks.push_back(task);
            }
        }
        inFile.close();
        cout << "Tasks loaded from" << filename << endl;
    }