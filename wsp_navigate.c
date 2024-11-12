#include "wsp_navigate.h"

void wsp_navigate(struct wsp_navigate_s *s) {
  if (s->repetitions_count == 0) {
    if (s->has_source_coordinates == 0) {
      s->source_y = s->source / s->grid_width;
      s->source_x = s->source - (s->grid_width * s->source_y);
      s->has_source_coordinates = 1;
    }

    if (s->has_destination_coordinates == 0) {
      s->destination_y = s->destination / s->grid_width;
      s->destination_x = s->destination - (s->grid_width * s->destination_y);
      s->has_destination_coordinates = 1;
    }

    if (s->source_x == s->destination_x) {
      s->source_x_step = 0;

      if (s->source_y < s->destination_y) {
        s->source_step = s->grid_width;
        s->source_y_step = 1;
        s->repetitions_count = s->destination_y - s->source_y;
      } else {
        if (s->source_y > s->destination_y) {
          s->source_step = -s->grid_width;
          s->source_y_step = -1;
          s->repetitions_count = s->source_y - s->destination_y;
        } else {
          s->source_step = 0;
          s->source_y_step = 0;
          s->repetitions_count = 0;
        }
      }
    } else {
      if (s->source_y == s->destination_y) {
        s->source_y_step = 0;

        if (s->source_x < s->destination_x) {
          s->source_step = 1;
          s->source_x_step = 1;
          s->repetitions_count = s->destination_x - s->source_x;
        } else {
          s->source_step = -1;
          s->source_x_step = -1;
          s->repetitions_count = s->source_x - s->destination_x;
        }
      } else {
        if (s->source_x < s->destination_x) {
          s->repetitions_count = s->destination_x - s->source_x;
          s->source_x_step = 1;

          if (s->source_y < s->destination_y) {
            s->source_step = s->grid_width + 1;
            s->source_y_step = 1;

            if ((s->destination_y - s->source_y) < s->repetitions_count) {
              s->repetitions_count = s->destination_y - s->source_y;
            }
          } else {
            s->source_step = -s->grid_width + 1;
            s->source_y_step = -1;

            if ((s->source_y - s->destination_y) < s->repetitions_count) {
              s->repetitions_count = s->source_y - s->destination_y;
            }
          }
        } else {
          s->repetitions_count = s->source_x - s->destination_x;
          s->source_x_step = -1;

          if (s->source_y < s->destination_y) {
            s->source_step = s->grid_width - 1;
            s->source_y_step = 1;

            if ((s->destination_y - s->source_y) < s->repetitions_count) {
              s->repetitions_count = s->destination_y - s->source_y;
            }
          } else {
            s->source_step = -s->grid_width - 1;
            s->source_y_step = -1;

            if ((s->source_y - s->destination_y) < s->repetitions_count) {
              s->repetitions_count = s->source_y - s->destination_y;
            }
          }
        }
      }
    }
  }

  s->source += s->source_step;
  s->source_x += s->source_x_step;
  s->source_y += s->source_y_step;
  s->repetitions_count--;
}
