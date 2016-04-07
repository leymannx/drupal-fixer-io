# Drupal 7 Fixer.io Currency Switcher

This is a ajaxified currency switcher module for drupal. Up-to-date exchange rates will get pulled automatically from http://fixer.io. This module offers a new field formatter for all decimal fields.

Optionally you can configure
- your own base currency,
- your own available currencies for the switcher
- and a different default currency for every activated language.

Additionally you also can configure the following field settings. Choose if the value should be displayed whether with
- a currency symbol prefixed or suffixed or with a
- a currency iso code prefixed or suffixed.
- Choose a thousand marker, a decimal marker and the number of digits to the right of the decimal.

Fixer.io is a free JSON API for current and historical foreign exchange rates published by the European Central Bank.
The rates are updated daily around 3PM CET.

@TODO offer field settings options for every activated language (since every language may have its own thousand marker and/or decimal marker).
