from setuptools import find_packages, setup

package_name = '01_wanderbot'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='KatsumiOuwa',
    maintainer_email='d2p.yggdrasill@gmail.com',
    description='TODO: Package description',
    license='Apache-2.0',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'wanderbot = 01_wanderbot.red_light_green_light:main',
        ],
    },
)
