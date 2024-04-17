pipeline {
	agent none

	triggers {
		cron('@daily')
	}

	stages {
		stage('Build') {
			agent {
				label 'os:windows'
			}

			steps {
				checkout scm
				dir("installer") {
					bat "pip install -r requirements.txt"
					bat "python publish.py"
				}
			}
		}
	}
}
