-- socket test
module Main where

import Network.Socket hiding (send, sendTo, recv, recvFrom) -- exclude these functions considering they deal with strings and not bytestrings
import Network.Socket.ByteString
import Crypto.Random
import System.Entropy
import Data.ByteString

main :: IO ()
main = do
  sock <- socket AF_INET Stream 0 -- create socket
  setSocketOption sock ReuseAddr 1
  bind sock (SockAddrInet 7777 iNADDR_ANY)
  listen sock 2
  mainLoop sock

mainLoop :: Socket -> IO ()
mainLoop sock = do
  conn <- accept sock     -- accept a connection and handle it
  runConn conn            -- run our server's logic
  mainLoop sock           -- repeat

runConn :: (Socket, SockAddr) -> IO ()
runConn (sock, _) = do
  randBytes <- getEntropy 256
  test.pack "test"
  -- let msg = show randBytes ++ "\n"
  send sock randBytes
  close sock
