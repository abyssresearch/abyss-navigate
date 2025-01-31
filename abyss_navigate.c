#include "abyss_navigate.h"

void abyss_navigate_initialize_bounds(const unsigned long width,
                                      const unsigned long height,
                                      struct abyss_navigate_s *s) {
  s->grid_width = width;
  s->grid_height = height;
  s->increment_bottom_left = width - 1;
  s->increment_bottom_right = width + 1;
  s->increment_top_center = -width;
  s->increment_top_left = -1 - width;
  s->increment_top_right = 1 - width;
}

void abyss_navigate_initialize_points(const unsigned long source,
                                      const unsigned long destination,
                                      struct abyss_navigate_s *s) {
  s->source = source;
  s->destination = destination;
  s->increment = 0;
  s->source_y = source / s->grid_width;
  s->source_x = source - (s->grid_width * s->source_y);
  s->destination_y = destination / s->grid_width;
  s->destination_x = destination - (s->grid_width * s->destination_y);
  s->repetitions_count = 0;
}

void abyss_navigate_increment(struct abyss_navigate_s *s) {
  if (s->repetitions_count == 0) {
    if (s->source_x == s->destination_x) {
      s->increment_x = 0;

      if (s->source_y != s->destination_y) {
        if (s->source_y < s->destination_y) {
          s->increment = s->grid_width;
          s->increment_y = 1;
          s->repetitions_count = s->destination_y - s->source_y;
          goto apply_increment;
        }

        s->increment = s->increment_top_center;
        s->increment_y = -1;
        s->repetitions_count = s->source_y - s->destination_y;
        goto apply_increment;
      }

      s->increment = 0;
      s->increment_y = 0;
      goto apply_increment;
    }

    if (s->source_y == s->destination_y) {
      s->increment_y = 0;

      if (s->source_x < s->destination_x) {
        s->increment = 1;
        s->increment_x = 1;
        s->repetitions_count = s->destination_x - s->source_x;
        goto apply_increment;
      }

      s->increment = -1;
      s->increment_x = -1;
      s->repetitions_count = s->source_x - s->destination_x;
      goto apply_increment;
    }

    if (s->source_x < s->destination_x) {
      s->increment_x = 1;
      s->repetitions_count = s->destination_x - s->source_x;

      if (s->source_y < s->destination_y) {
        s->increment = s->increment_bottom_right;
        s->increment_y = 1;

        if ((s->destination_y - s->source_y) < s->repetitions_count) {
          s->repetitions_count = s->destination_y - s->source_y;
        }

        goto apply_increment;
      }

      s->increment = s->increment_top_right;
      s->increment_y = -1;

      if ((s->source_y - s->destination_y) < s->repetitions_count) {
        s->repetitions_count = s->source_y - s->destination_y;
      }

      goto apply_increment;
    }

    s->increment_x = -1;
    s->repetitions_count = s->source_x - s->destination_x;

    if (s->source_y < s->destination_y) {
      s->increment = s->increment_bottom_left;
      s->increment_y = 1;

      if ((s->destination_y - s->source_y) < s->repetitions_count) {
        s->repetitions_count = s->destination_y - s->source_y;
      }

      goto apply_increment;
    }

    s->increment = s->increment_top_left;
    s->increment_y = -1;

    if ((s->source_y - s->destination_y) < s->repetitions_count) {
      s->repetitions_count = s->source_y - s->destination_y;
    }
  }

  apply_increment:
    s->source += s->increment;
    s->source_x += s->increment_x;
    s->source_y += s->increment_y;
    s->repetitions_count--;
}
