"""Developer Tools for the Morton C++ Library"""

import sys

from .make_user_presets import main as make_user_presets_main
from .run_user_workflows import main as run_user_workflow_main


def make_user_presets():
    sys.exit(make_user_presets_main(sys.argv))


def run_user_workflows():
    sys.exit(run_user_workflow_main(sys.argv))
