pipeline {
    agent any
    
    stages {
        stage('Clone Repository') {
            steps {
                script {
                    sh 'git clone https://github.com/ganeshak711/PES1UG22CS210_Jenkins.git'
                }
            }
        }
        
        stage('Build') {
            steps {
                script {
                    sh 'g++ -o PES1UG22CS210-1 PES1UG22CS210_Jenkins/PES1UG22CS210.cpp'
                }
            }
        }
        
        stage('Test') {
            steps {
                script {
                    sh './PES1UG22CS210-1'
                }
            }
        }
        
        stage('Deploy') {
            steps {
                echo 'deploy'
                // Add deployment steps here
            }
        }
    }
    
    post {
        failure {
            echo 'pipeline failed'
        }
    }
}
