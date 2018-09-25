## -*- encoding: utf-8 -*-
import os
from setuptools import setup
from setuptools.command.install import install

# Monkey patches xeus-cling to display type information in outputs
import shutil
class CustomInstallCommand(install):
    def run(self):
        file = "xmime.hpp"
        target = os.path.join(self.install_base, "include", "xcpp", file)
        print("manually copying {} to {} ".format(file, target))
        shutil.copyfile(file, target)
        install.run(self)

setup(
    name = "info-111",
    version = "0.1",
    description='Required software for using the Info-111 course material',
    url='http://nicolas.thiery.name/Enseignement/Info111/',
    author='Nicolas M. Thiéry et al.',
    author_email='Nicolas.Thiery@u-psud.fr',
    license='CC',
    classifiers=[
      'Development Status :: 4 - Beta',
      'Intended Audience :: Information Technology'
      'Topic :: Scientific/Engineering',
      'Programming Language :: C++',
    ], # classifiers list: https://pypi.python.org/pypi?%3Aaction=list_classifiers
    scripts=['bin/info-111'],
    cmdclass={
        'install': CustomInstallCommand,
    },
)
