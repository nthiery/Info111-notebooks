## -*- encoding: utf-8 -*-
import os
import sys
from setuptools import setup, Extension
from codecs import open # To open the README file with proper encoding
from setuptools.command.test import test as TestCommand # for tests

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
)
