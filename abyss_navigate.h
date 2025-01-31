#ifndef ABYSS_NAVIGATE_H
#define ABYSS_NAVIGATE_H

struct abyss_navigate_s {
  unsigned long grid_width;
  unsigned long grid_height;
  unsigned long source;
  unsigned long destination;
  long increment;
  long increment_bottom_left;
  long increment_bottom_right;
  long increment_top_center;
  long increment_top_left;
  long increment_top_right;
  char increment_x;
  char increment_y;
  unsigned long source_x;
  unsigned long source_y;
  unsigned long destination_x;
  unsigned long destination_y;
  unsigned long repetitions_count;
};

void abyss_navigate_initialize_bounds(const unsigned long width,
                                      const unsigned long height,
                                      struct abyss_navigate_s *s);

void abyss_navigate_initialize_points(const unsigned long source,
                                      const unsigned long destination,
                                      struct abyss_navigate_s *s);

void abyss_navigate_increment(struct abyss_navigate_s *s);

#endif
