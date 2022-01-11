let color = "#3AA757";

chrome.runtime.onInstalled.addListener(() =>
{
  chrome.storage.sync.set({ color });
  conosle.log(`Default background color set to ${color}`);
});
