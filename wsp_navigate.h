#ifndef WSP_NAVIGATE_H
#define WSP_NAVIGATE_H

struct wsp_navigate_s {
  unsigned long grid_width;
  unsigned long grid_height;
  unsigned long source;
  unsigned long destination;
  long source_step;
  unsigned long source_x;
  unsigned long source_y;
  unsigned long destination_x;
  unsigned long destination_y;
  char source_x_step;
  char source_y_step;
  unsigned long repetitions_count;
  unsigned char has_source_coordinates;
  unsigned char has_destination_coordinates;
};

void wsp_navigate(struct wsp_navigate_s *s);

#endif
