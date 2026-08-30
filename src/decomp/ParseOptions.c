// ParseOptions  entry=100002465

/* ParseOptions(char const*) */

void ParseOptions(char *param_1)

{
  _num_options = 0;
  _options = 0;
  _num_options = _cupsParseOptions(param_1,0,&_options);
  return;
}

