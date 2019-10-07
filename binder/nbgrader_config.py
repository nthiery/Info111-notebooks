import os
c = get_config()
c.CourseDirectory.course_id = 'Info111'

c.Exchange.root = '/public/info-111/exchange'
# Waiting for nbgader PR #1222
# c.CourseDirectory.submitted_directory = os.path.join(str(c.Exchange.root), str(c.CourseDirectory.course_id), "submitted")
c.ExchangeCollect.check_owner=False

c.CourseDirectory.ignore = ['.ipynb_checkpoints', '*.pyc', '__pycache__', 'feedback']
c.CourseDirectory.max_file_size = 100 # Kb
# CourseDirectory.include = [ '*.ipynb', '*.cpp' ]
