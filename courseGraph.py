courses = {}

#   COMP Classes
courses['COMP061'] = []  # No prerequisites
courses['COMP071'] = ['COMP061'] # Prerequisite is COMP061 
courses['COMP091'] = ['COMP071'] # Prerequisite is COMP071
courses['COMP092'] = ['COMP071'] # etc
courses['COMP120'] = ['MATH092', 'MATH093']
courses['COMP125'] = ['MATH092']
courses['COMP150'] = ['MATH092']
courses['COMP152'] = ['MATH093']
courses['COMP155'] = ['COMP150']
courses['COMP230'] = ['COMP155']
courses['COMP251'] = ['COMP125', 'COMP155', 'MATH125']
courses['COMP256'] = ['COMP125', 'COMP150']
courses['COMP325'] = ['COMP155']
courses['COMP331'] = ['COMP230', 'STAT270']
courses['COMP340'] = ['COMP251']
courses['COMP350'] = ['COMP251']
courses['COMP351'] = ['COMP251']
courses['COMP359'] = ['COMP251', 'MATH125', 'STAT270']
courses['COMP360'] = ['COMP251']
courses['COMP361'] = ['COMP251']
courses['COMP370'] = ['COMP251', 'CIS270']
courses['COMP371'] = ['CIS270', 'COMP230', 'COMP251']
courses['COMP380'] = ['COMP251', 'STAT270']
courses['COMP381'] = ['COMP251', 'STAT270']
courses['COMP382'] = ['COMP251', 'MATH225']
courses['COMP386'] = ['COMP359', 'COMP370']
courses['COMP390'] = ['MATH125', 'COMP251', 'STAT270']
courses['COMP420'] = [] 
courses['COMP430'] = ['COMP230', 'COMP251']
courses['COMP431'] = ['COMP230', 'STAT271', 'COMP331']
courses['COMP440'] = []
courses['COMP445'] = ['COMP390']
courses['COMP455'] = ['COMP251']
courses['COMP481'] = ['COMP251']
courses['COMP482'] = ['STAT270', 'COMP251']
courses['COMP486'] = ['COMP359', 'COMP370']
courses['COMP490'] = ['COMP390', 'STAT270']

#   MATH Classes
courses['MATH072'] = []
courses['MATH084'] = ['MATH072']
courses['MATH085'] = ['MATH084']
courses['MATH092'] = ['MATH085']
courses['MATH093'] = ['MATH092']
courses['MATH111'] = ['MATH092', 'MATH093']
courses['MATH112'] = ['MATH111']
courses['MATH125'] = ['MATH092']
courses['MATH225'] = ['MATH112']

#   STAT Classes
courses['STAT270'] = ['MATH112']
courses['STAT271'] = ['STAT270']

#  CIS Classes
courses['CIS270'] = ['COMP155']