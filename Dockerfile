# Compiles the Animation sources with g++ (Animation.sln still builds them on Windows).
# The program asks which animation to show, then draws it in the terminal until stopped.
FROM gcc:14 AS build
WORKDIR /src
COPY Animation/*.cpp Animation/*.h ./
RUN g++ -std=c++17 -O2 -static -o animation *.cpp

FROM debian:bookworm-slim
COPY --from=build /src/animation /usr/local/bin/animation
CMD ["animation"]
