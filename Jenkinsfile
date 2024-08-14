pipeline {
  agent none

  parameters {
    booleanParam(name: 'FORCE', defaultValue: false, description: 'Force update')
  }

  triggers {
    cron('@daily')
  }

  stages {
    stage('Build') {
      agent {
        label 'os:windows'
      }

      when {
        anyOf {
          changeset "**"
          expression { params.FORCE }
        }
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
