#!/bin/bash
tar cf testdir.tar testdir && \
(rm -rf out && \
  mkdir out && \
  cd out && \
  tar xf ../testdir.tar)
