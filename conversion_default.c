#include "main.h"

/**
 * handle_default - Handles an unknown conversion specifier.
 * @specifier: conversion specifier.
 *
 * Return: 2.
 */
int handle_default(char specifier)
{
	write(1, "%", 1);
	write(1, &specifier, 1);
	return (2);
}
